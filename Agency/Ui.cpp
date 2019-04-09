#include "Ui.h"
#include <iostream>
#include <string>

using namespace std;
Ui::Ui(Repo* repo) : repo{ repo } 
{}
Ui::~Ui()
{
	//for (auto o : this->repo->getOffers)
		//delete(o);
}
void Ui::printmenu()
{
	cout << "1.Add offer" << endl;
	cout << "2.Remove offer" << endl;
	cout << "3.Show" << endl;
	cout << "4.Undo" << endl;
	cout << "0.Exit" << endl;
}
void Ui::addO()
{
	double price,food;
	std::string name, val;
	cout << "1.offer 2.all inclusive" << endl;
	cin.ignore();
	getline(cin, val);
	cout << "Give name: " << endl;
	getline(cin, name);
	cout << "Give price" << endl;
	cin >> price;
	if (val == "1")
	{
		Offer* of = new Offer{ name,price };
		this->repo->add(of);
		undoActions.push_back(std::make_unique<UndoAdd>(repo, of));
	}
	if (val == "2")
	{
		cout << "Give foodvalue:" << endl;
		cin >> food;
		Offer* of = new All{ name,price,food };
		this->repo->add(of);
		undoActions.push_back(std::make_unique<UndoAdd>(repo, of));
	}
}
void Ui::removeO()
{
	double price, food;
	std::string name, val;
	cout << "1.offer 2.all inclusive" << endl;
	cin.ignore();
	getline(cin, val);
	cout << "Give name: " << endl;
	getline(cin, name);
	cout << "Give price" << endl;
	cin >> price;
	if (val == "1")
	{
		Offer* of = new Offer{ name,price };
		this->repo->remove(of);
		undoActions.push_back(std::make_unique<UndoRemove>(repo, of));
	}
	if (val == "2")
	{
		cout << "Give foodvalue:" << endl;
		cin >> food;
		Offer* of = new All{ name,price,food };
		this->repo->remove(of);
		undoActions.push_back(std::make_unique<UndoRemove>(repo, of));
	}
}
void Ui::undo() 
{
	if (undoActions.empty())
	{
		cout << "No more operations" << endl;
	}
	else
	{
		undoActions.back()->doundo();
		undoActions.pop_back();
	}
}


void Ui::show()
{
	for (auto o : this->repo->getOffers())
		cout << o->toString();
	string aux = "offers.txt";
	ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
void Ui::run()
{
	while (true)
	{
		this->printmenu();
		int com = 0;
		cout << "Enter command: ";
		cin >> com;
		if (com == 0)
			break;
		if (com == 1)
		{
			this->addO();
			this->repo->writeToFile();
		}
		if (com == 2)
		{
			this->removeO();	
			this->repo->writeToFile();
		}
		if (com == 3)
		{
			this->show();			
		}
		if (com == 4)
		{
			this->undo();
			this->repo->writeToFile();
		}
	}
}