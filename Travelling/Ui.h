#pragma once
#include "Repo.h"
class Ui
{
private:
	Repo repo;
public:
	Ui(Repo repo);
	~Ui();
	void printmenu();
	void addT();
	void removeT();
	void updateT();
	void run();
	void show();
};