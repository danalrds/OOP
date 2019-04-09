#include "Classes.h"
#include <iostream>
#include <sstream>
using namespace std;
Travel::Travel(const std::string _dest, const double _price) : dest{ _dest }, price{_price}
{}
Travel::~Travel()
{}
Air::Air(const std::string _dest, const double _price, const int _seat) :Travel{ _dest,_price }, seat{ _seat }
{
	
}
Air::~Air()
{}
std::string Air::toString() const
{
	stringstream buffer;
	buffer << this->getDest() << " " << this->getPrice()<< " " << this->getSeat() << endl;
	return buffer.str();
}
Train::Train(const std::string _dest, const double _price, const int _vagon) : Travel{ _dest,_price }, vagon{ _vagon }
{}
Train::~Train()
{}
std::string Train::toString() const
{
	stringstream buffer;
	buffer << this->getDest() << " " << this->getPrice() << " " << this->getVagon() << endl;
	return buffer.str();
}