#include "Ui.h"
#include "HeelShoe.h"
#include <iostream>
using namespace std;
void Ui::printMenu()
{
	cout << endl;
	cout << "1 - Add shoe." << endl;
	cout << "2 - Remove shoe." << endl;
	cout << "3 - Show." << endl;
	cout << "4 - Save" << endl;
	cout << "5 - Display" << endl;
	cout << "0 - Exit." << endl;
}
void Ui::addShoe()
{
	std::string name,type;
	double price;
	double high;
	cout << "Shoe or Heelshoe?" << endl;
	getline(cin, type);
	cout << "Give name: ";
	getline(cin, name);
	cout << "Give price: ";
	cin >> price;
	if (type == "heelshoe")
	{
		cout << "Give high: ";
		cin >> high;
		Shoe* shoe = new HeelShoe{ name,price,high };
		this->repo->add(shoe);
		//delete(shoe);
	}
	else
	{
		Shoe* shoe2 = new Shoe{ name,price };
		this->repo->add(shoe2);
		//delete(shoe2);
	}

}
void Ui::removeShoe()
{
	std::string name, type;
	double price;
	double high;
	cout << "Shoe or Heelshoe?" << endl;
	getline(cin, type);
	cout << "Give name: ";
	getline(cin, name);
	cout << "Give price: ";
	cin >> price;
	if (type == "heelshoe")
	{
		cout << "Give high: ";
		cin >> high;
		Shoe* shoe = new HeelShoe{ name,price,high };
		this->repo->remove(shoe);
		delete(shoe);
	}
	else
	{
		Shoe* shoe2 = new Shoe{ name,price };
		this->repo->remove(shoe2);
		delete(shoe2);
	}
}
void Ui::show()
{
	for (auto s : this->repo->getShoes())
	{
		cout << s->toString();
	}
}
Ui::~Ui()
{
	for (auto s : this->repo->getShoes())
		delete(s);
}
void Ui::run()
{
	while (true)
	{
		Ui::printMenu();
		int commandRepo{ 0 };
		cout << "Input the command: ";
		cin >> commandRepo;
		cin.ignore();
		if (commandRepo == 0)
			break;
		switch (commandRepo)
		{
		case 1:
			this->addShoe();
			break;
		case 2:
			this->removeShoe();
			break;	
		case 3:
			this->show();
			break;
		case 4:
			this->repo->writeToFile();
			break;
		case 5:
			this->repo->display();
			break;
		}		
	}
}