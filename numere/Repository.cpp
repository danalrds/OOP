#include "Repository.h"
using namespace std;

void Repository::add(int number)
{
	this->numere.push_back(number);
}
void Repository::update(int index, int newnumber)
{
	this->numere[index] = newnumber;
}
void Repository::remove(int pos)
{
	this->numere.erase(this->numere.begin()+pos);
}
int Repository::searchNumber(int number)
{
	bool ok = false;
	vector<int> lista = this->getNumbers();
	int index = 0;
	for (const int& i : lista)
	{
		if (i == number)
		{
			ok = true;
			break;
		}
		index++;
	}
	if (ok == false)
		return -1;
	return index;
}