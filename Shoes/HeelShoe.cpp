#include "HeelShoe.h"
#include <sstream>
#include <iostream>
using namespace std;
HeelShoe::HeelShoe(const std::string _name, const double _price, const double _high) : Shoe{ _name,_price }, high{_high}
{}
HeelShoe::~HeelShoe()
{}
std::string HeelShoe::toString() const
{
	stringstream buffer;
	buffer << this->name << " " << this->price <<" "<<this->high<< endl;
	return buffer.str();
}
