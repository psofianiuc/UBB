#include "taskmanager.h"
#include <sstream>

taskManager::taskManager(programmer& p, comtroller& c, QWidget *parent)
	: prog(p), ctrl(c), QWidget(parent)
{
	tasks = ctrl.returnTasksByStatus();
	this->ctrl.registerObserver(this);
	initWindow();
	populateList();
}

taskManager::~taskManager()
{
	ctrl.unregisterObserver(this);
}

void taskManager::initWindow()
{
	QHBoxLayout* layout = new QHBoxLayout(this);
	this->setWindowTitle(QString::fromStdString(prog.getName()));

	QWidget *mainWidget = new QWidget();
	QVBoxLayout *mainSide = new QVBoxLayout(mainWidget);

	taskList = new QListWidget();
	taskList->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget *data = new QWidget();
	QFormLayout *form = new QFormLayout(data);
	id = new QLineEdit();
	description = new QLineEdit();
	form->addRow("&Id: ", id);
	form->addRow("&Description: ", description);

	QWidget *buttonWidget = new QWidget();
	QGridLayout *grid = new QGridLayout(buttonWidget);
	addButton = new QPushButton("Add");
	removeButton = new QPushButton("Remove");
	done = new QPushButton("Done");
	start = new QPushButton("Start");
	grid->addWidget(addButton, 0, 0);
	grid->addWidget(removeButton, 0, 1);
	grid->addWidget(done, 0, 2);
	grid->addWidget(start, 0, 3);

	mainSide->addWidget(new QLabel("Students:"));
	mainSide->addWidget(taskList);
	mainSide->addWidget(data);
	mainSide->addWidget(buttonWidget);

	layout->addWidget(mainWidget);
	connectSignalsAndSlots();
}


void taskManager::populateList()
{
	if (taskList->count() > 0) taskList->clear();

	for (auto t : tasks)
	{
		std::stringstream id;
		id << t.getPid();
		QString itemForList = QString::fromStdString(t.getDescription() + "\t" + t.getStatus());
		taskList->addItem(itemForList);
	}
}

void taskManager::connectSignalsAndSlots()
{
	QObject::connect(taskList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemHasChanged()));
	//QObject::connect(addButton, SIGNAL(clicked()), this, SLOT(addTask()));
	QObject::connect(this->addButton, &QPushButton::clicked, this, [&]() { this->addTask();	});
	//QObject::connect(removeButton, SIGNAL(clicked()), this, SLOT(removeTask()));
	QObject::connect(this->removeButton, &QPushButton::clicked, this, [&]() { this->removeTask();	});
	//QObject::connect(done, SIGNAL(clicked()), this, SLOT(doneTask()));
	//QObject::connect(start, SIGNAL(clicked()), this, SLOT(startTask()));
	QObject::connect(this->done, &QPushButton::clicked, this, [&]() { this->doneTask();	});
	QObject::connect(this->start, &QPushButton::clicked, this, [&]() { this->startTask();});
}

int taskManager::getIndex()
{
	if (taskList->count() == 0) return -1;
	QModelIndexList index = this->taskList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		description->clear();
		id->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void taskManager::listItemHasChanged()
{
	int idx = this->getIndex();
	if (idx == -1)
		return;

	task t = tasks[idx];
	std::stringstream i;
	i << t.getPid();
	description->setText(QString::fromStdString(t.getDescription()));
	id->setText(QString::fromStdString(i.str()));
}

void taskManager::addTask()
{
	std::string d;
	int i;
	d = description->text().toStdString();
	i = id->text().toInt();
	task t(d,"open",i);
	try {
		ctrl.addTask(t);
	}
	catch (repositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
	tasks = ctrl.returnTasksByStatus();
	populateList();
}

void taskManager::removeTask()
{
	int idx = getIndex();
	if (idx < 0) return;

	task t = tasks[idx];
	ctrl.removeTask(t);
	tasks = ctrl.returnTasksByStatus();
	populateList();

}

void taskManager::doneTask()
{
	int idx = getIndex();
	if (idx < 0) return;

	task t = tasks[idx];
	try
	{
		int i = prog.getId();
		ctrl.done(t, i);
	}
	catch (repositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void taskManager::startTask()
{
	int idx = getIndex();
	if (idx < 0) return;

	task t = tasks[idx];
	try
	{
		int i = prog.getId();
		ctrl.start(t, i);
	}
	catch (repositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void taskManager::update()
{
	this->tasks = this->ctrl.returnTasksByStatus();

	if (taskList->count() > 0) taskList->clear();

	for (auto t : tasks)
	{
		std::stringstream id;
		id << t.getPid();
		QString itemForList = QString::fromStdString(t.getDescription() + "\t" + t.getStatus());
		taskList->addItem(itemForList);
	}
}