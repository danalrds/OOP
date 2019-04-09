#pragma once
#include <string>

class Animal
{
protected:
	std::string colour;
	double weight;

public:
	Animal(std::string _colour, double _weight);
	virtual ~Animal();

	std::string getColour() const { return this->colour; };
	double getWeight() const { return this->weight; };

	virtual std::string toString() const;

	virtual void speak() const = 0;
};


