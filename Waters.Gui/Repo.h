#pragma once
#include "Classes.h"
#include <vector>
#include <algorithm>
class Repo
{
private:
	std::vector<Water*> waters;
public:
	Repo();
	~Repo();
	int add(Water* w);
	void remove(Water* w);
	void update(Water* w);
	void writeToFile();
	double compute();
	int find(const std::string name);
	Water* findW(const std::string name);
	std::vector<Water*> getWaters() const { return waters; }
};