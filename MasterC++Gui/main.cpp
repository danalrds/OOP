#include <QtWidgets/QApplication>

#include "Controller.h"

#include "CSV.h"
#include <fstream>
#include <assert.h>
#include "GrUi.h"

int main(int argc, char* argv[])
{
	Repository repo{ "tutorials.txt" };
	Validator val;
	FilePlaylist* p = new CSVPlaylist{ "Playlist.csv" };
	Controller ctrl(repo, p, Validator{});
	QApplication a(argc, argv);
	TutorialGUI gui{ ctrl };
	gui.setWindowTitle("Tutorials C++");
	/*
	TableModel* tableModel = new TableModel{ p };
	Widget mainWidget{ p, tableModel, true };
	mainWidget.setWindowTitle("Playlist");
	mainWidget.show();
	*/
	gui.show();

    a.exec();
	delete p;
	
	return 0;
}