#include "Shoe.h"
#include <sstream>
#include <iostream>
using namespace std;
Shoe::Shoe(const std::string _name, const double _price) : name{ _name }, price{ _price }
{}
Shoe::~Shoe()
{}
std::string Shoe::toString() const
{
	stringstream buffer;
	buffer << this->name << " " << this->price << endl;
	return buffer.str();
}
