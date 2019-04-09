#include <iostream>
#include "Classes.h"
#include <assert.h>
#include "repo.h"
#include "Ui.h"
using namespace std;
void test()
{
	Character* ch1 = new God{ "ch1",14,300,"god"};
	assert(ch1->getName() == "ch1");
	assert(ch1->getDamage() == 14);
	assert(ch1->getStrength() == 300);
	Character* ch2 = new SuperH{ "ch2",15,400,"super" };
	assert(ch2->getName() == "ch2");
	assert(ch2->getDamage() == 15);
	assert(ch2->getStrength() == 400);
	Repo repo;
	repo.add(ch1);
	assert(repo.getChars().size() == 1);
	repo.add(ch2);
	assert(repo.getChars().size() == 2);
	delete(ch1);
	delete(ch2);
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