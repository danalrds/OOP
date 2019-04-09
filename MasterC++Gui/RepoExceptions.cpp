#include "RepoExceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg }
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateException::what()
{
	return "There is another tutorial with the same name and presenter!";
}
const char * InexistException::what()
{
	return "There is no tutorial with the given data!";
}
