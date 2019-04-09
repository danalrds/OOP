#pragma once
#include <vector>
#include "Employee.h"
class Company 
{
private:
	std::vector<Employee*> employees;
public:
	Company(const std::vector<Employee*> e) : employees(e) {}
	void add(const Employee & emp);
};