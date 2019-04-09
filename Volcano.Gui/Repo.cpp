#include "Repo.h"
using namespace std;
Repo::Repo()
{}
Repo::~Repo()
{}
void Repo::add(const Volcano v)
{
	this->volcanoes.push_back(v);
}
void Repo::update(const std::string name, const double height, const std::string city)
{
	int pos = this->find(name);
	Volcano v{ name,height,city };
	this->volcanoes[pos] = v;
}
int Repo::find(const std::string name)
{
	int pos = 0;
	for (auto v : this->volcanoes)
	{
		if (v.getName() == name)
			return pos;
		pos = pos + 1;
	}
	return -1;
}
Volcano Repo::findV(const std::string name)
{	
	for (auto v : this->volcanoes)
	{
		if (v.getName() == name)
			return v;		
	}	
}