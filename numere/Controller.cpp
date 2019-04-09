#include "Controller.h"
using namespace std;

void Controller::addNumber(int number)
{
	this->repo.add(number);	
}

void Controller::listAll()
{
	vector<int> lista = this->repo.getNumbers();
	for (const int& i : lista)
		cout << i << " ";
	cout << endl;
}

bool Controller::removeNumber(int number)
{
	int index = 0;	
	bool gasit = false;
	index = this->repo.searchNumber(number);
	if (index  >-1)
	{
		gasit = true;		
		this->repo.remove(index);
	}
	return gasit;
}

bool Controller::updateNumber(int number,int newnumber)
{	
	int index = 0;
	bool gasit = false;
	index= this->repo.searchNumber(number);	
	if (index  >-1)
	{
		gasit = true;		
		this->repo.update(index, newnumber);
	}
	return gasit;
}

