#include "UI.h"
using namespace std;
void UI::printMenu()
{
	cout << endl;
	cout << "1.List numbers" << endl;
	cout << "2.Add number" << endl;
	cout << "3.Remove number" << endl;
	cout << "4.Update numeber" << endl;
	cout << "5.Filter all numbers < a given value" << endl;
	cout << "0.Exit" << endl;
}
void UI::addNumberUI()
{
	int number = 0;
	cout << "Enter a number: ";
	cin >> number;
	this->ctrl.addNumber(number);
}

void UI::removeNumberUI()
{
	int number = 0; bool ok;
	cout << "Enter the number: ";
	cin >> number;
	ok=this->ctrl.removeNumber(number);
	if (ok == false)
		cout << "Number not found!" << endl;
}

void UI::updateUI()
{
	int number = 0; bool ok; int newnumber;
	cout << "Enter number you want to update: ";
	cin >> number;
	cout << "Enter new number: ";
	cin >> newnumber;
	ok = this->ctrl.updateNumber(number,newnumber);
	if (ok == false)
		cout << "Number not found!"<<endl;	
}

void UI::run()
{	
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		switch (command)
		{		
		case 1:
			this->ctrl.listAll();
			break;
		case 2:
			this->addNumberUI();
			break;
		case 3:
			this->removeNumberUI();
			break;
		case 4:
			this->updateUI();
		}
	}
}