#pragma once
#include "repositoryException.h"
#include "observer.h"
#include "task.h"
#include <vector>
#include <string.h>
#include <iostream> 

class repository : public Subject
{
private:
	std::vector<task> tasks;
	std::string fileName;

public:
	repository(const std::string& fN);
	~repository() {}

	void readFromFile();
	void saveToFile();

	bool findTask(task& t);

	/*
	Adds a task to the repository.
	First checks not to be duplicated;
	input: task - t
	output: updated repo
	*/
	void addTask(task& t);

	/*
	Removes a task from the repository.
	First checks to be in the repo;
	input: task - t
	output: updated repo
	*/
	void removeTask(task& t);
	/*
	Updates the status of a task without any conditions (except for the task to exists)
	input: task - t, std::string - status
	output: updated repo
	*/
	void updateStatus(task& t, std::string& status);
	/*
	Updates the status of a task to done if it is in progress and the pid of the task matches the id of programmer.
	If not, throws a repoException.
	It updates the task by calling updateStatus.
	input: task - t, int - id of programmer
	output: updated repo
	*/
	void done(task& t, int& id);
	/*
	Updates the status of a task to start if it is in open.
	If not, throws a repoException.
	It updates the task by calling updateStatus.
	input: task - t, int - id of programmer
	output: updated repo
	*/
	void start(task& t, int& id);

	std::vector<task> getTasks() { return tasks; }
	std::vector<task> filterByStatus();

	int getSize() { return tasks.size(); }
};

