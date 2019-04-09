#include "UI.h"
#include <Windows.h>
#include <assert.h>
using namespace std;
void tests()
{
	Repository repo{};
	Controller ctrl{ repo };
	
}
int main()
{
	system("color f1");
	tests();
	Repository repo{};	
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
	return 0;
}