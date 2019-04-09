#include "Manager.h"
#include <sstream>
#include <iostream>
using namespace std;
Manager::Manager(std::string _name, double _basesalary, double _bonus) :Employee{ _name,_basesalary }, bonus{_bonus}
{}
Manager::~Manager()
{}
std::string Manager::toString() const
{
	stringstream buffer;
	buffer << "Manager name: " << this->name << " basesalary: " << this->basesalary<<" bonus: "<<this->bonus << endl;
	return buffer.str();
}
double Manager::computeSalary() const
{
	return this->basesalary+this->bonus;
}