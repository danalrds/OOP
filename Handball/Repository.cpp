#include "Repository.h"
using namespace std;

void Repository::add(const Player& player)
{
	this->players.push_back(player);
}

int Repository::find(const Player& player)
{
	std::vector<Player> lista = this->getPlayers();
	for (int i = 0; i < lista.size();i++)
	{
		Player p = lista[i];
		if (p.getName() == player.getName())
			if (p.getCountry() == player.getCountry())
				if (p.getGoals() == player.getGoals())
					return i;
	}
	return -1;
}