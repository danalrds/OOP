#include <Windows.h>
#include "UI.h"
#include <assert.h>
using namespace std;
void tests()
{
	Repository repo{};	
	Controller ctrl{ repo };
	ctrl.addNumber(7);
	ctrl.addNumber(8);
	ctrl.addNumber(9);
	vector<int> lista =ctrl.getRepo().getNumbers();
	assert(lista.size() == 3);
	assert(ctrl.getRepo().searchNumber(8) == 1);
	assert(ctrl.getRepo().searchNumber(9) == 2);
	bool okk=ctrl.removeNumber(9);
	assert(ctrl.getRepo().getNumbers().size() == 2);
	assert(ctrl.getRepo().searchNumber(9) == -1);
	ctrl.updateNumber(7, 333);
	assert(ctrl.getRepo().searchNumber(7) == -1);
	assert(ctrl.getRepo().searchNumber(333) == 0);	
	bool ok=ctrl.removeNumber(333);
	assert(repo.searchNumber(333) == -1);
}
int main()
{ 
	system("color f1");
	tests();
	Repository repo{};
	repo.add(1);
	repo.add(2);
	repo.add(3);	
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
	return 0;
}