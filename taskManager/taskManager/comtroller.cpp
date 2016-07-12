#include "comtroller.h"

void comtroller::addTask(task& t)
{
	repo.addTask(t);
	notify();
}

void comtroller::removeTask(task& t)
{
	repo.removeTask(t);
	notify();
}

void comtroller::updateStatus(task& t,std::string& s)
{
	repo.updateStatus(t, s);
	notify();
}

void comtroller::done(task& t, int& id)
{
	repo.done(t, id);
	notify();
}

void comtroller::start(task& t, int& id)
{
	repo.start(t, id);
	notify();
}
