#include "UI.h"
#include <Windows.h>

int main()
{
	system("color f1");
	Repository repo{};
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
	return 0;
}