#pragma once
#include <string>
class Fragrance
{
private:
	std::string name;
	double price;
public:
	Fragrance(std::string name, double price);
	~Fragrance();
	std::string getName() const { return name; }
	double getPrice() const { return price; }
};