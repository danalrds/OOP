#include "Proiect.h"
#include <QtWidgets/QApplication>
#include "Repo.h"
#include <assert.h>
#include "PresenterWidget.h"
void test()
{
	Repo repo;
	assert(repo.getP().size() == 3);
	assert(repo.getQ().size() == 3);

}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test();
	Repo repo;
	Controller control{ repo };
	PresenterWidget* p = new PresenterWidget{ control };
	p->show();
	return a.exec();
}
