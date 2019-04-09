#include "WatersGui.h"
#include <QtWidgets/QApplication>
#include "Gui.h"
#include "Classes.h"
#include <assert.h>
#include "Repo.h"
void test()
{
	Water* w1 =new See{"Mediterana", 800,"Mediteranea"};
	assert(w1->getName()=="Mediterana");
	assert(w1->getSurf() == 800);
	assert(w1->getOld()=="Mediteranea");
	assert(w1->computeS() == 3200);
	Water* w2 = new Ocean{ "Atlantic", 1000,"Atlantico" };
	assert(w2->getName() == "Atlantic");
	assert(w2->getSurf() == 1000);
	assert(w2->getOld() == "Atlantico");
	assert(w2->computeS() == 5000);
	Repo repo;
	repo.add(w1);
	assert(repo.getWaters().size() == 1);
	repo.add(w2);
	assert(repo.getWaters().size()==2);
	repo.remove(w1);
	assert(repo.getWaters().size() == 1);
	Water* w3 = new Ocean{ "Atlantic", 1500,"Atlanticooo" };
	repo.update(w3);
	Water* w4 = repo.findW("Atlantic");
	assert(w4->getSurf() == 1500);
	assert(w4->getOld() == "Atlanticooo");
	assert(w4->computeS() == 7500);
}
int main(int argc, char *argv[])
{
	test();
	Water* w1 = new See{ "Mediterana", 800,"Mediteranea" };
	Water* w2 = new Ocean{ "Atlantic", 1000,"Atlantico" };	
	QApplication a(argc, argv);
	Repo repo;
	repo.add(w1);
	repo.add(w2);
	Gui w{repo};
	w.show();
	return a.exec();
}
