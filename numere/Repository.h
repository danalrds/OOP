#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
class Repository
{
private:
	std::vector<int> numere;
public:
	Repository(){}
	void add(int number);
	void update(int index, int number);
	void remove(int pos);
	std::vector<int>getNumbers() const { return numere; }
	int searchNumber(int number);	
};