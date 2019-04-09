#pragma once
#include <string>
class Travel
{
protected:
	std::string dest;
	double price;
public:
	Travel(const std::string _dest, const double _price);
	virtual ~Travel();
	std::string getDest() const { return dest; }
	double getPrice() const { return price; }
	virtual std::string toString() const= 0;
};

class Air :public Travel
{
private:
	int seat;
public:
	Air(const std::string _dest, const double _price,const int _seat);
	~Air();
	int getSeat() const { return seat; }
	std::string toString() const override;
};

class Train :public Travel
{
private:
	int vagon;
public:
	Train(const std::string _dest, const double _price, const int _vagon);
	~Train();
	int getVagon() const { return vagon; }
	std::string toString() const override;
};

