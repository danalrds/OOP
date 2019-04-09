#include "Ui.h"
#include "HeelShoe.H"
#include <iostream>
using namespace std;
int main()
{
	system("color f4");
	Repo* repo = new CSV{"shoes.txt"};
	Ui ui(repo);
	ui.run();
	_CrtDumpMemoryLeaks();
	//system("pause");
	return 0;
}