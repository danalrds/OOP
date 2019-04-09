#include "Team.h"
using namespace std;

void Team::addT(const Player& player)
{
	this->team.push_back(player);
}

int Team::findT(const Player& player)
{
	std::vector<Player> lista = this->getTeam();
	for (int i = 0; i < lista.size(); i++)
	{
		Player p = lista[i];
		if (p.getName() == player.getName())
			if (p.getCountry() == player.getCountry())
				if (p.getGoals() == player.getGoals())
					return i;
	}
	return -1;
}