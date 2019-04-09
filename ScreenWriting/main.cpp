#include "Screenwriting.h"
#include <QtWidgets/QApplication>
#include"WritingSession.h"
#include"writerWidget.h"
#include<assert.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo;
	Controller control(repo);
	control.readIdeasFromFile("ideas.txt");
	control.readWritersFromFile("writers.txt");
	//assert(control.getIdeas().size() == 4);
	WritingSession session(control);
	for (auto w : control.getWriters()) {
		writerWidget*writer = new writerWidget(session, w);
		writer->show();
	}
	return a.exec();
}


