#include "Repo.h"
#include <fstream>
#include <sstream>
using namespace std;
Repo::Repo()
{}
Repo::~Repo()
{}
int Repo::add(Water* w)
{
	int pos = find(w->getName());
	if (pos == -1)
	{
		this->waters.push_back(w);
		return 1;
	}
	else
		return -1;
}
void Repo::remove(Water* w)
{
	int pos = find(w->getName());
	this->waters.erase(this->waters.begin() + pos);
}
void Repo::update(Water* w)
{
	int pos = find(w->getName());
	this->waters[pos] = w;
}

int Repo::find(const std::string name)
{
	int pos = 0;
	for (auto w : this->waters)
	{
		if (w->getName() == name)
			return pos;
		pos = pos + 1;
	}
	return -1;
}
Water* Repo::findW(const std::string name)
{
	for (auto w : this->waters)
	{
		if (w->getName() == name)
			return w;		
	}
}
double Repo::compute()
{
	int s = 0;
	for (auto w : waters)
		s = s + w->getSurf();
	return s;
}
void Repo::writeToFile()
{
	ofstream file("water.txt");
	for (auto w : this->waters)
		file << w->toString();
	file.close();

}