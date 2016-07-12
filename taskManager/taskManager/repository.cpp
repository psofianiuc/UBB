#include "repository.h"
#include <string>
#include <fstream>



repository::repository(const std::string& fN)
{
	fileName = fN;
	readFromFile();
}


void repository::readFromFile() {
	std::ifstream f(fileName.c_str());
	std::string s, d;
	int pid;
	while (f >> d >> s >> pid)
	{
		task t(d, s, pid);
		tasks.push_back(t);
	}
	f.close();
}


void repository::saveToFile() {
	std::ofstream f(fileName.c_str());
	for (auto t : tasks)
	{
		f << t.getDescription() << " " << t.getStatus() << " " << t.getPid() << "\n";
	}
	f.close();
}

bool repository::findTask(task& t)
{
	for (auto task : tasks)
	{
		if (t == task) return true;
	}
	return false;
}

void repository::addTask(task& t)
{
	if (!findTask(t))
	{
		tasks.push_back(t);
		notify();
	}
	saveToFile();
}

void repository::removeTask(task& t)
{
	if (!findTask(t)) return;
	std::vector<task> aux;
	for (auto task : tasks)
	{
		if (!(t == task)) aux.push_back(task);
		notify();
	}
	tasks = aux;
	saveToFile();
}

void repository::updateStatus(task& t, std::string& status)
{
	for (int i = 0; i<getSize(); i++)
		if (tasks[i] == t)
		{
			tasks[i].setStatus(status);
			notify();

		}
	saveToFile();
}

void repository::done(task& t, int& id)
{
	for (int i = 0; i<getSize() - 1; i++)
		if (tasks[i] == t)
		{
			if (tasks[i].getStatus() == "progress" && tasks[i].getPid() == id)
			{
				updateStatus(t, (std::string) "closed");
			}
			else throw repositoryException("Not in progress or not the programmer.");

		}
}

void repository::start(task& t, int& id)
{
	for (int i = 0; i<getSize(); i++)
		if (tasks[i] == t)
		{
			if (tasks[i].getStatus() == "open") {
				updateStatus(t, (std::string) "progress");
				tasks[i].setPid(id);
			}
			else throw repositoryException("Not an opened project.");

		}
}

std::vector<task> repository::filterByStatus()
{
	std::vector<task> aux = getTasks();
	int ok;
	do
	{
		ok = 1;
		for(int i=0;i<getSize()-1;i++)
			if (aux[i].getStatus() < aux[i + 1].getStatus())
			{
				task t = aux[i];
				aux[i] = aux[i + 1];
				aux[i + 1] = t;
				ok = 0;

			}
	} while (ok == 0);
	tasks = aux;
	return aux;
}