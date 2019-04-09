#include "UI.h"
#include <Windows.h>
#include <assert.h>
using namespace std;
void tests()
{
	Repository repo{};
	Team theteam{};
	Controller ctrl{ repo };	
	Player p1{ "Cristina", "ROU",100 };
	Player p2{ "Isabele","SWE",74 };
	ctrl.addPlayer(p1);
	ctrl.addPlayer(p2);
	
	assert(ctrl.getRepo().getPlayers().size() == 2);
	assert(ctrl.getRepo().find(p1)==0);
	assert(ctrl.getRepo().find(p2) == 1);
	Player p3{ "Ecaterina","SWE",74 };
	ctrl.addPlayer(p3);
	assert(ctrl.getRepo().getPlayers().size() == 3);
	assert(ctrl.getRepo().find(p3) == 2);	
	
}
void test2()
{
	Team theteam{};
	Controller ctrl{ theteam };
	Player p1{ "Cristina", "ROU",100 };
	Player p2{ "Isabele","ROU",74 };
	Player p3{ "Ecaterina","SWE",74 };
	ctrl.addTeam(p1);
	ctrl.addTeam(p2);
	ctrl.addTeam(p3);
	assert(ctrl.getTeamC().getTeam().size() == 3);
	int s = ctrl.count("ROU");
	assert(s==174);
	
}
int main()
{
	system("color f1");
	tests();
	test2();
	Repository repo{};	
	Team theteam{};		
	Player p1{ "Cristina", "ROU",100 };
	Player p2{ "Isabele","ROU",74 };
	Player p3{ "Ecaterina","SWE",74 };
	theteam.addT(p1);
	theteam.addT(p2);
	theteam.addT(p3);
	Controller ctrl1{ theteam };	
	UI ui{ ctrl1};
	ui.run();
	return 0;
}