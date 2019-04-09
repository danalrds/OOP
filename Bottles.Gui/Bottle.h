#pragma once
#include <string>
class Bottle
{
private:
	std::string name;
	double price;
	std::string country;
public:
	Bottle(const std::string name, const double price, const std::string country);
	~Bottle();
	std::string getName() const { return name; }
	double getPrice() const { return price; }
	std::string getCountry() const { return country; }
};