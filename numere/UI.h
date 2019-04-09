#pragma once
#include <iostream>
#include "Controller.h"

class UI
{
private: 
	Controller ctrl;
public: 
	UI(const Controller& c) : ctrl(c) {}
	void run();
	static void printMenu();
	void addNumberUI();
	void removeNumberUI();
	void updateUI();

};