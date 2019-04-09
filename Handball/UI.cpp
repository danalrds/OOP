#include "UI.h"
#include <string>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1.List players" << endl;
	cout << "2.Add player" << endl;
	cout << "3.Sort by goals" << endl;	
	cout << "4.Count for country" << endl;
}

void UI::addPlayerUI()
{
	int goals;
	std::string name,country;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter country: ";
	getline(cin, country);
	cout << "Enter goals: ";
	cin >> goals;
	Player p{name,country,goals};
	ctrl.addPlayer(p);
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
			this->ctrl.list();
			break;
		}
		case 2:
		{
			this->addPlayerUI();
			break;
		}
		case 3:
		{
			this->ctrl.sortPlayers();
			break;
		}
		case 4:
		{
			int s = 0;
			std::string country;
			cout << "Enter country: ";
			getline(cin, country);
			 s = this->ctrl.count(country);
			cout << "They were scored " << s << "goals!" << endl;
			break;
		}
		}
	}
}
