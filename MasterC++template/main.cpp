#include <assert.h>
#include "Tutorial.h"
#include "UI.h"
#include <Windows.h>
#include <crtdbg.h>


using namespace std;

void tests()
{	
Repository rep{};
Repository rep2{};
Controller ctrl{ rep };
assert(ctrl.getRepo().findByTitle_Presenter("C++ Programming", "Derek Banas")==-1);
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("C++ Programming", "Derek Banas").getTitle()=="");
Tutorial t1{ "C++ Programming", "Derek Banas", Duration{ 70, 32 }, 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
Tutorial t2{ "Single Responsibility Principle", "kudvenkat", Duration{ 10, 23 }, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
Tutorial t3{ "C++ - lambda expressions", "Bradley Needham", Duration{ 14, 50 }, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU" };
Tutorial t4{ "C++", "Jimmy", Duration{ 70, 32 }, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
Tutorial t5{ "Single Responsibility Principle", "kudvenkat", Duration{ 14, 50 }, 777, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
ctrl.addTutorialToRepository("C++ Programming", "Derek Banas", 70, 32 , 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
ctrl.addTutorialToRepository("Single Responsibility Principle", "kudvenkat", 10, 23, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo");
assert(ctrl.getRepo().getTutorials().getSize()==2);
rep.getTutorials().remove(-1);
assert(ctrl.getRepo().getTutorials()[1].getPresenter()=="kudvenkat");
ctrl.addTutorialToRepository("C++ - lambda expressions", "Bradley Needham", 14, 50, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU");
assert(ctrl.getRepo().getTutorials().getSize() == 3);
ctrl.addTutorialToRepository("C++", "Jimmy", 70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
assert(ctrl.getRepo().getTutorials().getSize() == 4);
ctrl.addTutorialToRepository("C++", "Jimmy", 70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
assert(ctrl.getRepo().getTutorials().getSize() == 4);
ctrl.startPlaylist(); ctrl.nextPlaylist();
ctrl.deleteTutorialRepository("C++", "Jimmy");
ctrl.deleteTutorialRepository("C++ - lambda expressions", "Bradley Needham");
assert(ctrl.getRepo().getTutorials().getSize() == 2);
ctrl.addTutorialToRepository("C++", "Jimmy",70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
ctrl.deleteTutorialRepository("C++", "Jimmy");
ctrl.deleteTutorialRepository("C++ Programming", "Derek Banas");
assert(ctrl.getRepo().getTutorials().getSize() == 1);
ctrl.deleteTutorialRepository("C++ Programming", "Derek"); ///asta nu exista
assert(ctrl.getRepo().getTutorials().getSize() == 1);
ctrl.deleteTutorialRepository("Single Responsibility Principle", "kudvenkat");
assert(ctrl.getRepo().getTutorials().getSize() == 0);
ctrl.addTutorialToRepository("C++ Programming", "Derek Banas", 70, 32, 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
ctrl.addTutorialToRepository("Single Responsibility Principle", "kudvenkat", 10, 23, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo");
ctrl.updateTutorialRepository("C++ Programming", "Derek Banas", 14, 50, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU");
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("C++ Programming", "Derek Banas").getNrLikes()==602);
ctrl.updateTutorialRepository("Single Responsibility Principle", "kudvenkat", 14, 50, 777, "https://www.youtube.com/watch?v=5t-_wI7nFdU");
ctrl.updateTutorialRepository("C++", "Jimmy", 70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle", "kudvenkat").getDuration().getMinutes() == 14);
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle", "kudvenkat").getDuration().getSeconds() == 50);
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle", "kudvenkat").getNrLikes() == 777);
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle", "kudvenkat").getLink() == "https://www.youtube.com/watch?v=5t-_wI7nFdU");

/*
assert(ctrl.getRepo().find_Obj_ByTitle_Presenter("Single Responsibility Principle","kudvenkat") == t5);
ctrl.addTutorialToRepository("Single Responsibility Principle", "kudvenkat", 10, 23, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo");
DynamicVector v(2);
v.add(t2);
v.add(t5);
v = v - t5;
assert(v.getSize()==1);
assert(ctrl.getRepo().getTutorials().getSize() == 2);
*/
}

void test_playlist()
{	
	PlayList repo{};
	Controller ctrl{ repo };
	assert(ctrl.getPlaylist().isEmpty()==true);
	assert(ctrl.getPlaylist().getCurrentTutorial().getTitle()=="");
	assert(ctrl.getPlaylist().findByTitle_Presenter("C++ Programming", "Derek Banas") == -1);	
	Tutorial t1{ "C++ Programming", "Derek Banas", Duration{ 70, 32 }, 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
	Tutorial t2{ "Single Responsibility Principle", "kudvenkat", Duration{ 10, 23 }, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
	Tutorial t3{ "C++ - lambda expressions", "Bradley Needham", Duration{ 14, 50 }, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU" };
	Tutorial t4{ "C++", "Jimmy", Duration{ 70, 32 }, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
	Tutorial t5{ "Single Responsibility Principle", "kudvenkat", Duration{ 14, 50 }, 777, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
	ctrl.addTutorialToPlay(t1);
	ctrl.addTutorialToPlay(t3);
	assert(ctrl.getPlaylist().getTutorials().getSize() == 2);
	ctrl.addTutorialToPlay(t1);
	assert(ctrl.getPlaylist().getTutorials().getSize() == 2);
	ctrl.deleteTutorialPlaylist("C++ - lambda expressions", "Bradley Needham");
	assert(ctrl.getPlaylist().getTutorials().getSize() == 1);
	ctrl.deleteTutorialPlaylist("C++ Programming", "Derek nu exista");
	assert(ctrl.getPlaylist().getTutorials().getSize() == 1);
	ctrl.deleteTutorialPlaylist("C++ Programming", "Derek Banas");
	assert(ctrl.getPlaylist().getTutorials().getSize() == 0);	
	ctrl.addTutorialToRepository("C++", "Jimmy", 70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
	ctrl.addTutorialToRepository("C++ another one", "Jimmy", 77, 33, 880, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
	ctrl.toPlayByPresenter("Jimmy");
	assert(ctrl.getPlaylist().getTutorials().getSize()==2);		
	assert(ctrl.getPlaylist().getCurrentTutorial().getPresenter()=="Jimmy");
	ctrl.getPlaylist().play();
	ctrl.getPlaylist().next();
}

int main()
{
	system("color f5");
	{
		tests();
		test_playlist();
		Repository repo{};
		// add some tutorials
		Tutorial t1{ "C++ Programming", "Derek Banas", Duration{ 70, 32 }, 38000, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
		Tutorial t2{ "Single Responsibility Principle", "kudvenkat", Duration{ 10, 23 }, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo" };
		Tutorial t3{ "C++ - lambda expressions", "Bradley Needham", Duration{ 14, 50 }, 602, "https://www.youtube.com/watch?v=5t-_wI7nFdU" };
		Tutorial t4{ "C++", "Jimmy", Duration{ 70, 32 }, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY" };
		Tutorial t5{ "Polymorphism in C++", "easytuts4you", Duration{ 17, 56 }, 536, "https://www.youtube.com/watch?v=f2lMj2v63JU" };

		repo.addTutorial(t1);
		repo.addTutorial(t2);
		repo.addTutorial(t3);
		repo.addTutorial(t4);
		repo.addTutorial(t5);
		Controller ctrl{ repo };
		UI ui{ ctrl };
		ui.run();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
