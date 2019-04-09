#include "VolcanoGui.h"
#include <QtWidgets/QApplication>
#include "Gui.h"
#include "Volcano.h"
#include <assert.h>
#include "Repo.h"
void test()
{
	Volcano v{ "Vezuviu",1800,"Napoli" };
	assert(v.getName()=="Vezuviu");
	assert(v.getHeight() == 1800);
	assert(v.getCity() == "Napoli");
	Volcano v2{ "Etna",1600,"Sicilia" };
	Repo repo;
	repo.add(v);
	assert(repo.getVolcanoes().size() == 1);
	repo.add(v2);
	assert(repo.getVolcanoes().size() == 2);
	repo.update("Vezuviu", 1600, "Sicilia");
	Volcano v3 = repo.findV("Vezuviu");
	assert(v3.getHeight() == 1600);
	assert(v3.getCity() == "Sicilia");
}
int main(int argc, char *argv[])
{
	test();
	QApplication a(argc, argv);
	Volcano v{ "Vezuviu",1800,"Napoli" };
	Volcano v2{ "Etna",1900,"Sicilia" };
	Volcano v3{ "Caldera Yellowstone",2900,"Los Angeles" };
	Repo repo;
	repo.add(v);
	repo.add(v2);
	repo.add(v3);
	Gui w{ repo };
	w.show();
	return a.exec();
}
