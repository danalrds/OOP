#pragma once
#include "Classes.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Repo
{
private:
	std::vector<Travel*> travels;
public:
	Repo();
	~Repo();
	void add(Travel* t);
	void remove(Travel* t);
	void update(const std::string dest, Travel* t);
	int find(const std::string dest);
	std::vector<Travel*> getTravels() const { return travels; }
};