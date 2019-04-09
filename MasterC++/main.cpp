#include <assert.h>
#include "Tutorial.h"
#include "UI.h"
#include <Windows.h>
#include <crtdbg.h>
#include "RepoExceptions.h"
#include <fstream>
#include "CSV.h"
#include "HTML.h"
#include <iostream>
using namespace std;

void tests()
{	
Repository rep{ "test.txt" };
FilePlaylist* p = new CSVPlaylist{ "Playlist.csv" };
Controller ctrl{ rep,p,Validator{} };
assert(ctrl.getRepo().findByTitle_Presenter("C++ Programming", "Derek Banas")==-1);
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("C++ Programming", "Derek Banas").getTitle()=="");
Tutorial t1{ "C++ Programming", "Derek Banas", Duration{ 70, 32 }, 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
Tutorial t2{ "Single Responsibility Principle", "Kudvenkat", Duration{ 10, 23 }, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
Tutorial t3{ "C++ - lambda expressions", "Bradley Needham", Duration{ 14, 50 }, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU" };
Tutorial t4{ "C++", "Jimmy", Duration{ 70, 32 }, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
Tutorial t5{ "Single Responsibility Principle", "Kudvenkat", Duration{ 14, 50 }, 777, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
ctrl.addTutorialToRepository("C++ Programming", "Derek Banas", 70, 32 , 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
ctrl.addTutorialToRepository("Single Responsibility Principle", "Kudvenkat", 10, 23, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo");
assert(ctrl.getRepo().getTutorials().size()==2);
assert(ctrl.getRepo().getTutorials()[1].getPresenter()=="Kudvenkat");
ctrl.addTutorialToRepository("C++ - lambda expressions", "Bradley Needham", 14, 50, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU");
assert(ctrl.getRepo().getTutorials().size() == 3);
ctrl.addTutorialToRepository("C++", "Jimmy", 70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
assert(ctrl.getRepo().getTutorials().size() == 4);
ctrl.startPlaylist(); ctrl.nextPlaylist();
ctrl.deleteTutorialRepository("C++", "Jimmy");
ctrl.deleteTutorialRepository("C++ - lambda expressions", "Bradley Needham");
assert(ctrl.getRepo().getTutorials().size() == 2);
ctrl.addTutorialToRepository("C++", "Jimmy",70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
ctrl.deleteTutorialRepository("C++", "Jimmy");
ctrl.deleteTutorialRepository("C++ Programming", "Derek Banas");
assert(ctrl.getRepo().getTutorials().size() == 1);
ctrl.deleteTutorialRepository("Single Responsibility Principle", "Kudvenkat");
assert(ctrl.getRepo().getTutorials().size() == 0);
ctrl.addTutorialToRepository("C++ Programming", "Derek Banas", 70, 32, 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
ctrl.addTutorialToRepository("Single Responsibility Principle", "Kudvenkat", 10, 23, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo");
ctrl.updateTutorialRepository("C++ Programming", "Derek Banas", 14, 50, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU");
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("C++ Programming", "Derek Banas").getNrLikes()==602);
ctrl.updateTutorialRepository("Single Responsibility Principle", "Kudvenkat", 14, 50, 777, "https://www.youtube.com/watch?v=5t-_wI7nFdU");
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle", "Kudvenkat").getDuration().getMinutes() == 14);
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle", "Kudvenkat").getDuration().getSeconds() == 50);
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle", "Kudvenkat").getNrLikes() == 777);
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle", "Kudvenkat").getLink() == "https://www.youtube.com/watch?v=5t-_wI7nFdU");
std::ofstream ofs;
ofs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
ofs.close();
delete p;

}

void test_playlist()
{	
	FilePlaylist* p = new CSVPlaylist{ "Playlist.csv" };
	Repository rep{"test.txt"};
	Controller ctrl{ rep,p ,Validator{} };
	assert(ctrl.getPlaylist()->isEmpty() == true);
    assert(ctrl.getPlaylist()->getCurrentTutorial().getTitle()=="");	
	assert(ctrl.getPlaylist()->findByTitle_Presenter("C++ Programming", "Derek Banas") == -1);	
	Tutorial t1{ "C++ Programming", "Derek Banas", Duration{ 70, 32 }, 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
	Tutorial t2{ "Single Responsibility Principle", "kudvenkat", Duration{ 10, 23 }, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
	Tutorial t3{ "C++ - lambda expressions", "Bradley Needham", Duration{ 14, 50 }, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU" };
	Tutorial t4{ "C++", "Jimmy", Duration{ 70, 32 }, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
	Tutorial t5{ "Single Responsibility Principle", "kudvenkat", Duration{ 14, 50 }, 777, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
	ctrl.addTutorialToPlay(t1);
	ctrl.addTutorialToPlay(t3);
	assert(ctrl.getPlaylist()->getTutorials().size() == 2);		
	ctrl.deleteTutorialPlaylist("C++ - lambda expressions", "Bradley Needham");
	assert(ctrl.getPlaylist()->getTutorials().size() == 1);	
	ctrl.deleteTutorialPlaylist("C++ Programming", "Derek Banas");
	assert(ctrl.getPlaylist()->getTutorials().size() == 0);		
	ctrl.addTutorialToRepository("C++", "Jimmy", 70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
	ctrl.addTutorialToRepository("C++ another one", "Jimmy", 77, 33, 880, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
	ctrl.toPlayByPresenter("Jimmy");
	assert(ctrl.getPlaylist()->getTutorials().size()==2);		
	assert(ctrl.getPlaylist()->getCurrentTutorial().getPresenter()=="Jimmy");
	std::ofstream ofs;
	ofs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	std::ofstream ofs2;
	ofs2.open("playlist.csv", std::ofstream::out | std::ofstream::trunc);
	ofs2.close();
	
}

int main()
{
	system("color f5");
	{
		tests();
		test_playlist();
		std::string stor;
		cout << "Where do you want to store the data? csv/html" << endl;
		getline(cin, stor);
		try
		{		
			Repository repo("Tutorials.txt");
			if (stor == "html")
			{
				
				FilePlaylist* p = new HTMLPlaylist{ "Playlist.html" };
				Controller ctrl(repo, p, Validator{});
				UI ui(ctrl);
				ui.run();
				delete p;
			}
			else if (stor == "csv")
			{
				FilePlaylist* p = new CSVPlaylist{ "Playlist.csv" };
				Controller ctrl(repo, p, Validator{});
				UI ui(ctrl);
				ui.run();
				delete p;
			}
			std::ofstream ofs2;
			ofs2.open("playlist.csv", std::ofstream::out | std::ofstream::trunc);
			ofs2.close();			
		}
		catch (FileException&)
		{
			cout << "Repository file could not be opened! The application will terminate." << endl;
			return 1;
		}		
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
