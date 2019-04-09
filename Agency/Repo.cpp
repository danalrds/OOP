#include "Repo.h"
#include <iostream>
#include <fstream>
using namespace std;
Repo::Repo()
{}
Repo::~Repo()
{}
int Repo::find(const std::string name)
{
	int pos = 0;
	for (auto o : this->offers)
	{
		if (o->getName() == name)
			return pos;
		pos = pos + 1;
	}
	return -1;
}
void Repo::add(Offer* offer)
{
	int pos;
	pos = this->find(offer->getName());
	if (pos == -1)
		this->offers.push_back(offer);
	else
		cout << "already in repo" << endl;
}

void Repo::remove(Offer* offer)
{
	int pos;
	pos = this->find(offer->getName());
	if (pos != -1)
		this->offers.erase(this->offers.begin()+pos);
	else
		cout << "not in repo" << endl;
}

Csv::Csv(const std::string filename)
{
	this->filename = filename;	
}
Csv::~Csv()
{}

void Csv::writeToFile() const
{
	ofstream file(this->filename);	
	for (auto o : this->getOffers())
		file << o->toString();
	file.close();
}
Special::Special(const std::string filename)
{
	this->filename = filename;
}
Special::~Special()
{}

void Special::writeToFile() const
{
	ofstream file(this->filename);
	int pos = 1;
	for (auto o : this->getOffers())
	{
		file << "offer number " << pos << endl;
		file << o->toString();
		pos = pos + 1;
	}
	file.close();
}
