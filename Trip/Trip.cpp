#include "Trip.h"

Trip::Trip()
{
	this->dest = "";
	this->days = 0;
	this->price = 0;
}

Trip::~Trip()
{}

Trip::Trip(const std::string& dest, const int days, const double price)
{
	this->dest = dest;
	this->days = days;
	this->price = price;
}
