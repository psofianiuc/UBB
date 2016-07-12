#pragma once
#include "repository.h"
#include "observer.h"

class comtroller: public Subject
{
private:
	repository repo;

public:
	comtroller(repository& r) : repo(r) {}
	~comtroller() {}

	void addTask(task& t);
	void removeTask(task& t);
	void updateStatus(task& t, std::string& s);
	void done(task& t, int& id);
	void start(task& t, int& id);

	void readFile() { repo.readFromFile(); }
	std::vector<task> returnTasksByStatus() { return repo.filterByStatus(); }
};

