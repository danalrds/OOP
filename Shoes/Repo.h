#pragma once
#include "Shoe.h"
#include <vector>
#include <algorithm>
class Repo
{
private:
	std::vector<Shoe*> shoes;
public:
	Repo();	
	void add( Shoe* shoe);
	void remove(Shoe* shoe);
	std::vector<Shoe*> getShoes() const { return shoes; }
	int find(const std::string name, const double price);	
	virtual ~Repo();
	virtual void writeToFile() const = 0;
	virtual void display() const = 0;
};