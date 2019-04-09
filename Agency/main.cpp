#include <iostream>
#include <Windows.h>
#include <shellapi.h>
#include "Classes.h"
#include <assert.h>
#include "Repo.h"
#include "Ui.h"
using namespace std;
void test()
{
	Offer* of1 = new Offer{ "offer1",790 };
	assert(of1->getName() == "offer1");
	assert(of1->getPrice() == 790);
	Offer* of2 = new All{ "offer2",900,500 };
	assert(of2->getName() == "offer2");
	assert(of2->getPrice() == 900);
	Repo* repo = new Csv{"offers.txt"};
	repo->add(of1);
	repo->add(of2);
	assert(repo->getOffers().size() == 2);
	repo->remove(of1);
	assert(repo->getOffers().size() == 1);
	repo->remove(of2);
	assert(repo->getOffers().size() == 0);
	delete(of1);
	delete(of2);
}
int main()
{
	system("color f4");
	test();
	std::string com;
	cout << "csv or special" << endl;
	getline(cin, com);
	
	if (com == "csv")
	{
		
		Repo* repo = new Csv{ "offers.txt" };
		Ui ui(repo);
		ui.run();
	}
	if (com == "special")
	{		
		Repo* repo = new Special{ "offers.txt" };
		Ui ui(repo);
		ui.run();
	}
	_CrtDumpMemoryLeaks();
	//system("pause");
	return 0;
} 