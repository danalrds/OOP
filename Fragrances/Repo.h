#pragma once
#include <vector>
#include <algorithm>
#include "Fragrance.h"
class Repo
{
private:
	std::vector<Fragrance> fragrances;
public:
	Repo();
	~Repo();
	std::vector<Fragrance> getFrag() const { return fragrances; }
	void add(Fragrance f);
	void remove(std::string name);
	int find(std::string name);
	Fragrance findF(std::string name);
};