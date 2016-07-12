#pragma once
#include<iostream>
#include<string.h>

class task
{
private:
	std::string description;
	std::string status;
	int pId;
public:
	task(const std::string& d, const std::string& s, int p) : description(d), status(s), pId(p) {}
	~task() {}

	int getPid() { return pId; }
	std::string getDescription() { return description; }
	std::string getStatus() { return status; }

	void setStatus(const std::string& s) { status = s; }
	void setPid(const int& i) { pId = i; }

	bool operator ==(const task& t);
};

