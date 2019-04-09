#pragma once
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include <string>
class Player
{
private:
	std::string name;
	std::string country;
	int goals;	
public:
	Player();
	~Player();
	Player(const std::string& name, const std::string& country, const int goals);
	std::string getName() const { return name; }
	std::string getCountry() const { return country; }
	int getGoals() const { return goals; }

};