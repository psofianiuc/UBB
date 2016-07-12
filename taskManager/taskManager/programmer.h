#pragma once
#include<iostream>
#include<string.h>

class programmer
{
private:
	std::string name;
	int id;
public:
	programmer(const std::string& n, const int& i) : name(n), id(i) {}
	~programmer() {}

	int getId() { return id; }
	std::string getName() { return name; }

	bool operator==(programmer& p) { return id == p.id; }
};

