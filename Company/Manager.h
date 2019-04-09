#pragma once
#include "Employee.h"
class Manager : public Employee
{
private:
	double bonus;
public:
	Manager(std::string _name, double _basesalary, double _bonus);
	~Manager();
	double getBonus() const { return this->bonus; };
	std::string toString() const override;
	double computeSalary() const override;
};