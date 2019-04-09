#include "Fragrances.h"
#include <QtWidgets/QApplication>
#include "Gui.h"
#include "Fragrance.h"
#include <assert.h>
#include "Repo.h"
void tests()
{
	Fragrance f1{ "Aqua di Gioia",145 };
	Fragrance f2{ "Euphoria",245 };
	Fragrance f3{ "Black Orchid",345 };
	assert(f1.getName() == "Aqua di Gioia");
	assert(f1.getPrice() == 145);
	Repo repo;
	repo.add(f1);
	assert(repo.getFrag().size() == 1);
	repo.add(f2);
	assert(repo.getFrag().size() == 2);
	repo.remove("Aqua di Gioia");
	assert(repo.getFrag().size() == 1);
	repo.add(f3);
	assert(repo.getFrag().size() == 2);
	assert(repo.find("Aqua di Gioia")==-1);
	assert(repo.find("Euphoria")==0);
}
int main(int argc, char *argv[])
{
	tests();
	QApplication a(argc, argv);
	Fragrance f1{ "Aqua di Gioia",145 };
	Fragrance f2{ "Euphoria",245 };
	Fragrance f3{ "Black Orchid",345 };
	Repo repo;
	repo.add(f1);
	repo.add(f2);
	repo.add(f3);
	Gui w{repo};
	w.show();
	return a.exec();
}
