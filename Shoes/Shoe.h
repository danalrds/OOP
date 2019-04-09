#pragma once
#include <Windows.h>
#include <shellapi.h>
#include <string>
class Shoe
{
protected:
	std::string name;
	double price;
public:
	Shoe(const std::string _name,const double _price);
	virtual ~Shoe();
    std::string getName() const { return name; }
	double getPrice() const { return price; }
	virtual std::string toString() const;
};
