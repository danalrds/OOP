#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& c) :ctrl(c) {};
	static void printMenu();
	void addCommUI();
	void removeCommUI();
	void updateCommUI();
	void run();
};