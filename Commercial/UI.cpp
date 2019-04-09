#include "UI.h"
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1.Add" << endl;
	cout << "2.Remove" << endl;
	cout << "3.Update" << endl;
	cout << "4.List" << endl;
}

void UI::addCommUI()
{
	std::string name, link;
	int duration;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter link: ";
	getline(cin, link);
	cout << "Enter duration";
	cin >> duration;
	Commercial com {name,link,duration };
	this->ctrl.addComm(com);

}

void UI::removeCommUI()
{
	std::string name, link;
	int duration;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter link: ";
	getline(cin, link);
	cout << "Enter duration";
	cin >> duration;
	Commercial com{ name,link,duration };
	this->ctrl.removeComm(com);

}

void UI::updateCommUI()
{
	std::string name, link,newname,newlink;
	int duration,newduration;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter link: ";
	getline(cin, link);
	cout << "Enter duration";
	cin >> duration;
	cout << "Enter newname: ";
	getline(cin, newname);
	cout << "Enter newnewlink: ";
	getline(cin, newlink);
	cout << "Enter duration: ";
	cin >> newduration;
	Commercial com{ name,link,duration };
	Commercial com2{newname,newlink,newduration };
	this->ctrl.updateComm(com,com2);

}


void UI::run()
{
	while (true)
	{
		UI::printMenu();
		cout << "Enter command: ";
		int command;
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
			this->addCommUI();
			break;
		case 2:
			this->removeCommUI();
			break;
		case 3:
			this->updateCommUI();
			break;
		case 4:
			this->ctrl.listAll();
			break;
		}
	}
}