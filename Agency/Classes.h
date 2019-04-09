#pragma once
#include <Windows.h>
#include <shellapi.h>
#include <string>
class Offer
{
protected:
	std::string name;
	double price;
public:
	Offer(const std::string _name, const double _price);
	~Offer();
	std::string getName() const { return name; }
	double getPrice() const {return price;}
	virtual std::string toString() const;
};

class All : public Offer
{
private:
	double food;
public:
	All(const std::string _name, const double _price, const double _food);
	~All();
	double getFood() const { return food; }
	std::string toString() const override;
};