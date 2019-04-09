#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;
public:
	Controller(const Repository& r) : repo(r) {};
	void addComm(const Commercial& comm);
	void removeComm(const Commercial& comm);
	void updateComm(const Commercial& comm, const Commercial& newcomm);
	void listAll();
	Repository getRepo() const { return repo; }

};
