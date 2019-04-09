#include "Ui.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Ui::Ui(Repo repo) : repo{ repo }
{}
Ui::~Ui()
{
	//for (auto o : this->repo->getOffers)
	//delete(o);
}
void Ui::printmenu()
{
	cout << "1.Add char" << endl;	
	cout << "2.Show" << endl;
	cout << "3.Strike" << endl;
	cout << "4.Save" << endl;
	cout << "0.Exit" << endl;
}
void Ui::addC()
{
	int damage,strength;
	std::string name, val;
	cout << "1.God 2.SuperH" << endl;
	cin.ignore();
	getline(cin, val);
	cout << "Give name: " << endl;
	getline(cin, name);
	cout << "Give damage" << endl;
	cin >> damage;
	cout << "Give strength" << endl;
	cin >> strength;
	if (val == "1")
	{
		Character* ch = new God{ name,damage,strength ,"god"};
		this->repo.add(ch);
	}
	if (val == "2")
	{
		Character* ch = new SuperH{ name,damage,strength,"super" };
		this->repo.add(ch);
	}
}
void Ui::strike()
{	
	std::string conk,targ;	
	cin.ignore();
	cout << "Give striker: " << endl;
	getline(cin, conk);
	cout << "Give target: " << endl;
	getline(cin, targ);
	this->repo.update(conk, targ);
	//undoActions.push_back(std::make_unique<Undo>(repo, ));
}


void Ui::show()
{
	for (auto o : this->repo.getChars())
		cout << o->getName()<<" "<<o->getDamage()<<" "<<o->getStrength()<<endl;
	
}

void Ui::save()
{	
	ofstream file("chars.txt");
	for (auto o : this->repo.getChars())
		file << o->getName() << " " << o->getDamage() << " " << o->getStrength() << endl;
	file.close();
	string aux = "chars.txt";
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
			this->addC();			
		}
		
		if (com == 2)
		{
			this->show();
		}
		if (com == 3)
		{
			this->strike();
		}
		if (com == 4)
		{
			this->save();
		}
		
	}
}