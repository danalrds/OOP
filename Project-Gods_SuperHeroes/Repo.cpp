#include "Repo.h"
#include <fstream>
Repo::Repo()
{}
Repo::~Repo()
{}
void Repo::add(Character* ch)
{
	this->chars.push_back(ch);
}

void Repo::upt(Character* ch1, Character* ch2)
{
	int pos = find(ch1->getName());
	if (pos!=-1)
		this->chars[pos] = ch2;
}
void Repo::update(const std::string conk, const std::string targ)
{
	int pos = find(conk);
	int pos2 = find(targ);
	Character* con = this->getChars()[pos];
	std::string type;
	type = con->getType();
	int damage = con->getDamage();

	Character* tar = this->getChars()[pos2];
	std::string type2;
	type2 = tar->getType();
	int strength = tar->getStrength();
	strength = strength - damage;
	std::string name;
	//int damage = tar->getDamage();
	//name = tar->getName();
	if (type2 == "super")
	{
		Character* ch = new SuperH{tar->getName(),tar->getDamage(),strength,"super"};
		this->chars[pos2] = ch;
	}
	if (type2 == "god")
	{
		Character* ch = new God{ tar->getName(),tar->getDamage(),strength,"god" };
		this->chars[pos2] = ch;
	}

}
int Repo::find(const std::string name)
{
	int pos = 0;
	for (auto c : this->getChars())
	{
		if (c->getName() == name)
			return pos;
		pos = pos + 1;
	}
	return -1;
}
