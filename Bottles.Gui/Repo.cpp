#include "Repo.h"
using namespace std;
Repo::Repo()
{}
Repo::~Repo()
{}
void Repo::add(const Bottle b)
{
	int pos = find(b.getName());
	if (pos == -1)
		this->bottles.push_back(b);
}
void Repo::remove(const Bottle b)
{
	int pos = find(b.getName());
	if (pos != -1)
		this->bottles.erase(this->bottles.begin() + pos);
}
int Repo::find(const std::string name)
{
	int pos = 0;
	for (auto b : this->bottles)
	{
		if (b.getName() == name)
			return pos;
		pos = pos + 1;
	}
	return -1;
}
Bottle Repo::findBottle(const std::string name)
{
	int pos = 0;
	for (auto b : this->bottles)
	{
		if (b.getName() == name)
			return b;
		pos = pos + 1;
	}
}