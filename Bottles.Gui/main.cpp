#include "BottlesGui.h"
#include "Gui.h"
#include <QtWidgets/QApplication>
#include "Repo.h"
#include <assert.h>
void test()
{
	Bottle b{ "Whiskey",805.1,"America" };
	assert(b.getName()=="Whiskey");
	assert(b.getPrice() == 805.1);
	assert(b.getCountry() == "America");
	Repo repo;
	repo.add(b);
	assert(repo.getBottles().size() == 1);
	Bottle b2{ "Vodka",905.1,"Rusia" };
	repo.add(b2);
	assert(repo.getBottles().size() == 2);
	repo.remove(b);
	assert(repo.getBottles().size() == 1);
	assert(repo.find("Whiskey")== -1);
}

int main(int argc, char *argv[])
{
	test();
	QApplication a(argc, argv);
	Bottle b{ "Whiskey",805.1,"America" };
	Bottle b2{ "Vodka",905.1,"Rusia" };	
	Bottle b3{ "Rom",105.1,"India" };
	Repo repo;
	repo.add(b);
	repo.add(b2);
	repo.add(b3);
	Gui w{repo};
	w.show();
	return a.exec();
}
