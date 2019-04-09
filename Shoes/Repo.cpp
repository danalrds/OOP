#include "Repo.h"
#include <iostream>
using namespace std;
Repo::Repo()
{}
Repo::~Repo()
{}
void Repo::add( Shoe* shoe)
{
	int pos = this->find(shoe->getName(), shoe->getPrice());
	
	if (pos == -1)
		this->shoes.push_back(shoe);
	else
		cout << "already in repo" << endl;
}
int Repo::find(const std::string name, const double price)
{
	int pos = 0;	
	for (auto s : this->shoes)
	{		
		if ((s->getName() == name) && (s->getPrice() == price))
			return pos;
		pos = pos + 1;
	}
	return -1;
}
void Repo::remove(Shoe* shoe)
{
	int pos = this->find(shoe->getName(), shoe->getPrice());
	if (pos != -1)
		this->shoes.erase(this->shoes.begin()+pos);
	else
		cout << "not in in repo" << endl;
}
