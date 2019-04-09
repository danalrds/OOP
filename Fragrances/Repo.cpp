#include "Repo.h"
Repo::Repo()
{}
Repo::~Repo()
{}
void Repo::add(Fragrance f)
{
	this->fragrances.push_back(f);
}
void Repo::remove(std::string name)
{
	int pos = find(name);
	this->fragrances.erase(this->fragrances.begin() + pos);

}
int Repo::find(std::string name)
{
	int pos = 0;
	for (auto f : fragrances)
	{
		if (f.getName() == name)
			return pos;
		pos = pos + 1;
	}
	return -1;
}

Fragrance Repo::findF(std::string name)
{
	for (auto f : fragrances)
	{
		if (f.getName() == name)
			return f;		
	}
}