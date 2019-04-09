#include <Windows.h>
#include <crtdbg.h>
#include "Classes.h"
#include <assert.h>
#include <iostream>
#include "Repo.h"
#include "Ui.h"
using namespace std;
void test()
{
	Travel* t1 = new Air{ "mallorca",800,45 };	
	assert(t1->getDest()=="mallorca");
	assert(t1->getPrice() == 800);	
	Travel* t = new Train{ "Hawaii",800,45 };
	assert(t->getDest() == "Hawaii");
	assert(t->getPrice() == 800);
	
	Repo repo;
	repo.add(t1);
	repo.add(t);
	assert(repo.getTravels().size() == 2);
	repo.remove(t);
	assert(repo.getTravels().size() == 1);
	repo.update("mallorca", t);
	assert(repo.getTravels()[0]->getDest()=="Hawaii");
	delete(t1);
	delete(t);
}
int main()
{
	system("color f4");
	test();
	Repo repo;
	Ui ui(repo);
	ui.run();
	_CrtDumpMemoryLeaks();
	//system("pause");
	return 0;
}