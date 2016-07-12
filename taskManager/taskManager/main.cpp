#include "taskmanager.h"
#include <QtWidgets/QApplication>

#include <assert.h>
#include "comtroller.h"
#include<fstream>
#include <string>

void testTask();
void testRepo();
void testController();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	void testTask();
	void testRepo();
	void testController();
	std::ifstream f("prog.txt");
	std::string name;
	int id;
	f >> name >> id;
	programmer p1(name, id);
	f >> name >> id;
	programmer p2(name, id);
	f >> name >> id;
	programmer p3(name, id);
	repository r("tasks.txt");
	comtroller c(r);
	taskManager w1(p1,c);
	taskManager w2(p2,c);
	taskManager w3(p3,c);
	w1.show();
	w2.show();
	w3.show();

	return a.exec();
}


void testTask()
{
	task t("bbb", "aaa", 1);
}

void testRepo()
{
	repository repo("testTask.txt");
	task t("bbb", "aaa", 1);
	assert(repo.getSize() == 3);
	repo.addTask(t);
	assert(repo.getSize() == 4);
	repo.removeTask(t);
	assert(repo.getSize() == 3);
}

void testController()
{
	repository repo("testTask.txt");
	comtroller ctrl(repo);
	task t("bbb", "open", 5);
	int id = 5;
	ctrl.start(t, id);
	id = 3;
	try
	{
		ctrl.start(t, id);
		assert(false);
	}
	catch (repositoryException& e)
	{
		assert(true);
	}
	try
	{
		ctrl.done(t, id);
		assert(false);
	}
	catch (repositoryException& e)
	{
		assert(true);
	}
	id = 5;
	ctrl.done(t, id);
	ctrl.updateStatus(t, (std::string)"open");
	ctrl.removeTask(t);
}