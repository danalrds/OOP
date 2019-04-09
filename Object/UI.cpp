#include "UI.h"
#include <string>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1.List trips" << endl;
	cout << "2.Add trip" << endl;
	cout << "3.Remove trip" << endl;
	cout << "4.Update trip" << endl;
}

void UI::addTripUI()
{
	int days;
	double price;
	std::string dest;
	cout << "Enter destination: ";
	getline(cin, dest);
	cout << "Enter days: ";
	cin >> days;
	cout << "Enter price: ";
	cin >> price;
	Trip t{ dest,days,price };
	this->ctrl.addTrip(t);
}



void UI::listAll()
{
	this->ctrl.list();
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command = 0;
		cout << "Input command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			this->listAll();
			break;
		}
		case 2:
		{
			this->addTripUI();
			break;
		}
		case 3:
		{
			//this->removeTripUI();
			//break;
		}
		case 4:
		{
			//this->updateTripUI();
			//break; 
		}
		}
	}
}
