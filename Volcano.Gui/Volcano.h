#pragma once
#include <string>
class Volcano
{
private:
	std::string name;
	double height;
	std::string city;
public:
	Volcano(const std::string name, const double height, const std::string city);
	~Volcano();
	std::string getName() const { return name; }
	double getHeight() const { return height; }
	std::string getCity() const { return city; }
};