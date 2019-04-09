#pragma once
#include <string>
class Employee
{
protected:
	std::string name;
	double basesalary;
public:
	Employee(std::string _name, double _basesalary);
	virtual ~Employee();
	std::string getName() const { return this->name; };
	double getSalary() const { return this->basesalary; };
	virtual std::string toString() const;
	virtual double computeSalary() const;
};
