#pragma once
#include <vector>
#include <algorithm>
#include "Bottle.h"
class Repo
{
private:
	std::vector<Bottle> bottles;
public:
	Repo();
	~Repo();
	std::vector<Bottle> getBottles() const { return bottles; }
	void add(const Bottle b);
	void remove(const Bottle b);
	int find(const std::string name);
	Bottle findBottle(const std::string name);
};