#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& c) : ctrl(c) {}
	void run();
	static void printMenu();	
	void addPlayerUI();	
};