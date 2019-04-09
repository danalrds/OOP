#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;
public:
	Controller(const Repository& r) : repo(r) {}
	Repository getRepo() const { return repo; }
	void addNumber(int number);
	void listAll();
	bool removeNumber(int number);
	bool updateNumber(int number,int newnumber);

};
