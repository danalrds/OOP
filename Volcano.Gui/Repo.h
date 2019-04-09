#pragma once
#include "Volcano.h"
#include <vector>
#include <algorithm>
class Repo 
{
private:
	std::vector<Volcano> volcanoes;
public:
	Repo();
	~Repo();
	void add(const Volcano v);
	void update(const std::string name, const double height,const std::string city);
	std::vector<Volcano> filter();
	int find(const std::string name);
	Volcano findV(const std::string name);
	std::vector<Volcano> getVolcanoes() const { return volcanoes; }
};