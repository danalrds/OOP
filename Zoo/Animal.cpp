#include "Animal.h"
#include <sstream>
#include <iostream>

using namespace std;

Animal::Animal(std::string _colour, double _weight) : colour{ _colour }, weight{ _weight }
{
	//cout << "Constructing an animal." << endl;
}

Animal::~Animal()
{
	//cout << "Animal is being destroyed." << endl;
}

std::string Animal::toString() const
{
	stringstream buffer;
	buffer << "Animal \n\t weight: " << this->weight << " kg" << endl << "\t colour: " << this->colour << endl;
	return buffer.str();
}
