#include "Classes.h"
#include <sstream>
using namespace std;
Water::Water(const std::string name, const double surface, const std::string old) : name{ name }, surface{ surface }, old{old}
{};
Water::~Water()
{};

See::See(const std::string name, const double surface, const std::string old) : Water{name, surface, old}
{};
See::~See()
{};
double See::computeS() const
{
	return 4 * this->getSurf();
}

Ocean::Ocean(const std::string name, const double surface, const std::string old) : Water{ name, surface, old }
{};
Ocean::~Ocean()
{};

double Ocean::computeS() const
{
	return 5 * this->getSurf();
}
std::string Water::toString()
{
	stringstream buffer;
	buffer << this->getName() << " " << this->getSurf() << " " << this->getOld() << endl;
	return buffer.str();
}