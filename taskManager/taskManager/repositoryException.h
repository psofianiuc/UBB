#pragma once
#include <string.h>
#include <exception>
#include<iostream>

class repositoryException : public std::exception
{
protected:
	std::string message;

public:
	repositoryException();
	repositoryException(const std::string& msg);
	virtual ~repositoryException() {}
	virtual const char* what();
};

