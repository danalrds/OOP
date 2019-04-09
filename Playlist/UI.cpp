#include "UI.h"
#include <string>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1.List songs" << endl;
	cout << "2.Add song" << endl;
	cout << "3.Given an artist and duration the most similar in heaviness" << endl;
	cout << "4.Given a duration the heaviest mix" << endl;
}

void UI::addSongUI()
{
	int id,duration;
	double heavy;
	std::string title;
	std::string artist;
	cout << "Enter id: ";
	cin >> id;	
	cout << "Enter title: ";
	getline(cin, title);
	cin.ignore();	
	cout << "Enter artist: ";
	getline(cin, artist);
	cin.ignore();	
	cout << "Enter duration: ";
	cin >> duration;
	cout << "Enter heaviness: ";
	cin >> heavy;

	Song s{ id, title,artist,duration,heavy };
	this->ctrl.addSong(s);
}
void UI::makePlaylist()
{
	std::string  artist;
	int duration;
	cout << "Enter artist: ";
	getline(cin, artist);
	cout << "Enter duration: ";
	cin >> duration;
	std::vector<Song> songgs =this->ctrl.make(artist,duration);
	this->ctrl.list(songgs);
}

void UI::printMix()
{
	int duration;	
	cout << "Enter duration: ";
	cin >> duration;
	std::vector<Song> lista=this->ctrl.Mix(duration);
	this->ctrl.list(lista);
}


void UI::listAll()
{
	std::vector<Song> lista = this->ctrl.getRepo().getSongs();
	this->ctrl.list(lista);
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
			this->addSongUI();
			break;
		}
		case 3:
		{
			this->makePlaylist();
			break;
			
		}
		case 4:
		{
			this->printMix();
			break;
		}
		}
	}
}
