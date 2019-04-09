#pragma once
#include "Repo.h"
#include "Undo.h"
#include <memory>
class Ui
{
private:
	
	Repo* repo;
	std::vector<std::unique_ptr<Action>> undoActions;
public:
	Ui(Repo* repo);
	~Ui();
	void printmenu();
	void addO();
	void removeO();
	void run();
	void undo();
	void show();
};