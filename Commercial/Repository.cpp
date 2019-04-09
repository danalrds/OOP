#include "Repository.h"
using namespace std;
void Repository::add(const Commercial& comm)
{
	this->commercials.push_back(comm);
}

void Repository::remove(const int pos)
{
	this->commercials.erase(this->commercials.begin() + pos);
}

void Repository::update(const int pos, const Commercial& comm)
{
	this->commercials[pos] = comm;
}

int Repository::findComm(const std::string& link)
{
	for (int i = 0; i < this->commercials.size(); i++)
	{		
		Commercial com = this->commercials[i];
		if (com.getLink() == link)
			return i;
	}
	return -1;
}