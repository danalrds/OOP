#pragma once
#include <string>
class Water
{
private:
	std::string name;
	double surface;
	std::string old;
public:
	Water(const std::string name, const double surface, const std::string old);
	~Water();
	std::string getName() const { return name; }
	double getSurf() const { return surface; }
	virtual double computeS()const =0;
	std::string getOld() const { return old; }
    std::string toString();
};

class See :public Water
{
public:
	See(const std::string name, const double surface, const std::string old);
	~See();
	double computeS() const override;
};

class Ocean :public Water
{
public:
	Ocean(const std::string name, const double surface, const std::string old);
	~Ocean();
	double computeS() const override;
};