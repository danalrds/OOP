#pragma once
#include "Repo.h"

#include "CSV.h"
class Ui 
{
private:
	Repo* repo;	
public:
	Ui( Repo* r) : repo(r) {}
	~Ui();
	void run();
	void show();
	void printMenu();	
	void addShoe();
	void removeShoe();
};