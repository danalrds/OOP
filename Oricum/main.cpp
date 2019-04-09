#include "Oricum.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include <assert.h>
#include "Widget.h"
void test()
{
	Repo repo;
	//assert(repo.getI().size() == 2);

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test();
	Repo repo;
	Controller control{ repo };	
	for (auto u : control.getU())
	{
		Widget* w = new Widget(control, u);
		w->show();
	}
	a.exec();
	repo.printToFile();
	return 0;
}
