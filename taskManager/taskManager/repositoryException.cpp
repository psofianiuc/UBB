#include "repositoryException.h"

repositoryException::repositoryException() : exception(), message("")
{
}

repositoryException::repositoryException(const std::string & msg) : message(msg)
{
}

const char * repositoryException::what()
{
	return this->message.c_str();
}



