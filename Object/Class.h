#pragma once
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include <string>
class Trip
{
private:
	std::string dest;
	int days;
	double price;
public:
	Trip();
	~Trip();
	Trip(const std::string& dest, const int days, const double price);
	std::string getDest() const { return dest; }	
	int getDays() const { return days; }
	double getPrice() const { return price; }	
};