#include "Employee.h"
#include <sstream>
#include <iostream>
using namespace std;
Employee::Employee(std::string _name, double _basesalary) : name{ _name }, basesalary{ _basesalary }
{}
Employee::~Employee()
{}
std::string Employee::toString() const
{
	stringstream buffer;
	buffer << "name: " << this->name << " basesalary: " << this->basesalary << endl;
	return buffer.str();
}
double Employee::computeSalary() const
{
	return this->basesalary;
}