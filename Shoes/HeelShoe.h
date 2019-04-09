#pragma once
#include "Shoe.h"
class HeelShoe: public Shoe
{
private:
	double high;
public:
	HeelShoe(const std::string _name, const double _price, const double _high);
	~HeelShoe();
	double getHigh() const { return high; };
	std::string toString() const override;
};
