#pragma once
#include "Repo.h"
#include <memory>
#include "Undo.h"
class Ui
{
private:

	Repo  repo;
	//std::vector<std::unique_ptr<Action>> undoActions;
	
public:
	Ui(Repo repo);
	~Ui();
	void printmenu();
	void addC();
	void run();
	void save();
	void show();
	void strike();	
};
