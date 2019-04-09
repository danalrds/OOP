#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;
public:	
	Controller(const Repository& r) : repo(r) {}
	Repository getRepo() const { return repo; }
	void addTrip(const Trip& excursie);
	void removeTrip(const Trip& excursie);
	void updateTrip(const Trip& excursie, const Trip& excursienew);
	void list();

};