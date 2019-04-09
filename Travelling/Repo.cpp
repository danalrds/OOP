#include "Repo.h"
using namespace std;
Repo::Repo()
{}
Repo::~Repo()
{}
void Repo::add(Travel* t)
{
	std::string dest;
	dest = t->getDest();
	int pos = find(dest);
	if (pos == -1)
		this->travels.push_back(t);
	else
		cout << "already in repo" << endl;
	
}
int Repo::find(const std::string dest)
{
	int pos = 0;
	for (auto t : this->travels)
	{
		if (t->getDest() == dest)
			return pos;
		pos = pos + 1;
    }
	return -1;
}
void Repo::remove(Travel* t)
{
	std::string dest;
	dest = t->getDest();
	int pos = find(dest);
	if (pos!= -1)
		this->travels.erase(this->travels.begin()+pos);
	else
		cout << "not in repo" << endl;
}
void Repo::update(const std::string dest, Travel* t)
{
	int pos = find(dest);
	if (pos != -1)
	{
		this->travels.erase(this->travels.begin() + pos);
		this->travels.push_back(t);
	}
	else
		cout << "not in repo" << endl;
}


