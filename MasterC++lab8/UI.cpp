#include "UI.h"
#include "Windows.h"
#include <shellapi.h>
#include <string>
#include "Validator.h"
#include "RepoExceptions.h"
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator interface." << endl;
	cout << "2 - User interface." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printAdminMenu()
{	
	cout << "\t 1 - Add tutorial." << endl;
	cout << "\t 2 - Delete tutorial." << endl;
	cout << "\t 3 - Update tutorial." << endl;
	cout << "\t 4 - Display all." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printUserMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - See tutorials by presenter." << endl;
	cout << "\t 2 - Add tutorial." << endl;	
	cout << "\t 3 - Next." << endl;
	cout << "\t 4 - Delete tutorial." << endl;
	cout << "\t 5 - Show playlist." << endl;
	cout << "\t 6 - Play." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::addTutorialToRepo()
{	
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	double minutes = 0, seconds = 0;
	cout << "Enter the duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	double nrLikes;	
	cout << "\Enter nrLikes: ";
	cin >> nrLikes;
	cin.ignore();
	cout << "Youtube link: ";
	std::string link;
	getline(cin, link);
	try
	{
		this->ctrl.addTutorialToRepository(title,presenter,minutes,seconds,nrLikes,link);
	}
	catch (Exception& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}	
}


void UI::deleteTutorialRepo()
{
	cout << "Enter title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter presenter: ";
	std::string presenter;
	getline(cin, presenter);	
	try
	{
		ctrl.deleteTutorialRepository(title, presenter);		
	}
	catch (Exception& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}	
}


void UI::updateTutorialRepo()
{
	cout << "Enter title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter presenter: ";
	std::string presenter;
	getline(cin, presenter);
	double minutes = 0, seconds = 0;
	cout << "Enter new duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	double nrLikes;
	cout << "\Enter new  nrLikes: ";
	cin >> nrLikes;
	cin.ignore();
	cout << "New Youtube link: ";
	std::string link;
	getline(cin, link);
	try
	{
		this->ctrl.updateTutorialRepository(title, presenter, minutes, seconds, nrLikes, link);
	}
	catch (Exception& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}   
}

void UI::displayAllTutorialsRepo()
{
	std::vector<Tutorial> v = this->ctrl.getRepo().getTutorials();
	
	if (v.size()==0)
		return;
	if (v.size() == 0)
	{
		cout << "There are no tutorials in the repository." << endl;
		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		Tutorial s = v[i];
		Duration d = s.getDuration();
		cout << s.getTitle() << "; " << s.getPresenter() << "; " << d.getMinutes() << ":" << d.getSeconds() << ";Likes:" << s.getNrLikes() << "; " << endl;
	}
}

void UI::addTutorialToPlaylist()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);

	// search for the song in the repository
	Tutorial s = this->ctrl.getRepo().find_Obj_ByTitle_Presenter(title, presenter);
	if (s.getTitle() == "" && s.getTitle() == "")
	{
		cout << "There are no tutorials with the given data in the repository. Nothing will be added to the playlist." << endl;
		return;
	}

	this->ctrl.addTutorialToPlay(s);
}

void UI::displayPlaylist()
{
	std::vector<Tutorial> tutorials = this->ctrl.getPlaylist().getTutorials();	
	
	if (tutorials.size() == 0)
	{
		cout << "There are no tutorials in the playlist." << endl;
		return;
	}

	for (int i = 0; i < tutorials.size(); i++)
	{
		Tutorial s = tutorials[i];
		Duration d = s.getDuration();
		cout << s.getTitle() << "; " << s.getPresenter() << "; " << d.getMinutes() << ":" << d.getSeconds() << ";Likes:" << s.getNrLikes() << "; " << endl;
	}
	std::string filename = "playlist.csv";
	ShellExecuteA(NULL, NULL, "notepad.exe", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void UI::showPlaylistByPresenter()
{
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	this->ctrl.toPlayByPresenter(presenter);
	this->ctrl.startPlaylist();
}


void UI::deleteFromPlaylist()
{
	cout << "Enter title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter presenter: ";
	std::string presenter;
	getline(cin, presenter);
	Tutorial s = this->ctrl.getRepo().find_Obj_ByTitle_Presenter(title, presenter);	
	this->ctrl.deleteTutorialPlaylist(title, presenter);	
	int command{ 0 };
	cout << "\Do you want to rate it? 1.Yes 2.No";
	cin >> command;
	cin.ignore();
	if (command == 1)
	{
		this->ctrl.updateTutorialRepository(s.getTitle(),s.getPresenter(),s.getDuration().getMinutes(),
				s.getDuration().getSeconds(),s.getNrLikes()+1,s.getLink());
	}	
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

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addTutorialToRepo();
					break;
				case 2:
					this->deleteTutorialRepo();
					break;
				case 3:
					this->updateTutorialRepo();
					break;
				case 4:
					this->displayAllTutorialsRepo();
					break;
				}
			}
		}

		// playlist management
		if (command == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->showPlaylistByPresenter();
					break;
				case 2:
					this->addTutorialToPlaylist();					
					break;				
				case 3:
				{
					if (this->ctrl.getPlaylist().isEmpty())
					{
						cout << "Nothing to play, the playlist is empty." << endl;
						continue;
					}
					this->ctrl.nextPlaylist();
					Tutorial s = this->ctrl.getPlaylist().getCurrentTutorial();
					cout << "Now playing: " << s.getTitle() << " - " << s.getPresenter() << endl;
					break;
				}
				case 4:
					this->deleteFromPlaylist();					
					break;
				case 5:
					this->displayPlaylist();
					break;
				case 6:
				{
					if (this->ctrl.getPlaylist().isEmpty())
					{
						cout << "Nothing to play, the playlist is empty." << endl;
						continue;
					}
					this->ctrl.startPlaylist();
					Tutorial s = this->ctrl.getPlaylist().getCurrentTutorial();					
					break;
				}
				}
			}
		}
	}
}