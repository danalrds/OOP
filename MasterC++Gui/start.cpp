#include <QtWidgets/QApplication>

#include "Controller.h"
#include "GUI.h"
#include "HTML.h"
#include <fstream>
#include <assert.h>


void Initials(Controller ctrl) {
	ctrl.addTutorialToRepository("C++ Programming", "Derek Banas", 70, 32 , 38000,"https://www.youtube.com/watch?v=Rub-JsjMhWY");
	ctrl.addTutorialToRepository("Single Responsibility Principle", "kudvenkat", 10, 23, 96, "https://www.youtube.com/watch?v=hGf2upfDpdo");
	ctrl.addTutorialToRepository("C++", "Jimmy",70, 32, 380, "https://www.youtube.com/watch?v=Rub-JsjMhWY" );
};
Tutorial t3{
};
	


int main(int argc, char* argv[]) {
	//tests();
	
	{
		QApplication a(argc, argv);
		Repository repo{"tutorials.txt"};
		Validator val;	
		FilePlaylist* p = new HTMLPlaylist{ "Playlist.html" };
		Controller ctrl(repo, p, Validator{});		
		Initials(ctrl);
		//TutorialGUI gui{ ctrl };
		//gui.setWindowTitle("Tutorials C++");
		//gui.show();

		//a.exec();
		delete p;
	}

	return 0;
}