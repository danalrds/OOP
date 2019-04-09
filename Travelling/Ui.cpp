#include "Ui.h"
#include <iostream>
using namespace std;
Ui::Ui(Repo repo)
{}
Ui::~Ui()
{}
void Ui::printmenu()
{
	cout << "1.Add travel" << endl;
	cout << "2.Remove travel" << endl;
	cout << "3.Update travel" << endl;
	cout << "4.Show" << endl;
	cout << "0.Exit" << endl;
}
void Ui::addT()
{
	std::string dest,val;
	double price;
	cin.ignore();
	cout << "1.train  2.air" << endl;	
	getline(cin, val);		
	cout << "Give dest: "<<endl;
	getline(cin, dest);	
	cout << "Give price:"<<endl;
	cin >> price;	
	//cin.ignore();
	if (val == "1")
	{
		int vag;
		cout << "Give vagon: ";
		cin >> vag;
		Travel* t = new Train{ dest,price,vag };
		this->repo.add(t);
	}
	if (val == "2")
	{
		int seat;
		cout << "Give seat: ";
		cin >> seat;
		Travel* t = new Air{ dest,price,seat };
		this->repo.add(t);
	}	
}
void Ui::show()
{
	for (auto t : this->repo.getTravels())
		cout << t->toString();
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
			this->addT();
		}
		if (com == 4)
		{
			this->show();
		}

	}
}

