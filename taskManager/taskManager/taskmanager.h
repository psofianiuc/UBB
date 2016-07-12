#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QtWidgets/QMainWindow>
#include "ui_taskmanager.h"
#include <QMessageBox>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "comtroller.h"
#include "observer.h"
#include "programmer.h"
#include<vector>

class taskManager : public QWidget, public Observer
{
	Q_OBJECT

public:
	taskManager(programmer& p, comtroller& c, QWidget *parent = 0);
	~taskManager();

private:
	Ui::taskManagerClass ui;
	comtroller& ctrl;
	programmer prog;
	std::vector<task> tasks;

	QLineEdit *description;
	QLineEdit *id;
	QPushButton *addButton;
	QPushButton *removeButton;
	QPushButton *done;
	QPushButton *start;
	QListWidget *taskList;

	void initWindow();
	void populateList();
	void connectSignalsAndSlots();
	int getIndex();

	void update() override;
	void addTask();
	void removeTask();
	void doneTask();
	void startTask();

	private slots:
	void listItemHasChanged();

};

#endif // TASKMANAGER_H
