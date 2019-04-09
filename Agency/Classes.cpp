#include "Classes.h"
#include <iostream>
#include <sstream>
using namespace std;
Offer::Offer(const std::string _name, const double _price) : name{ _name }, price{ _price }
{}
Offer::~Offer()
{}
std::string Offer::toString()const
{
	stringstream buffer;
	buffer << this->getName()<< " " << this->getPrice() << endl;
	return buffer.str();
}

All::All(const std::string _name, const double _price, const double _food) : Offer{ _name,_price }, food{_food}
{}
All::~All()
{}
std::string All::toString()const
{
	stringstream buffer;
	buffer << this->getName() << " " << this->getPrice() <<" "<<this->getFood()<< endl;
	return buffer.str();
}