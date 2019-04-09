#pragma once
#include "Player.h"

class Team
{
private:
	std::vector<Player> team;
public:
	Team() {}
	void addT(const Player& player);
	std::vector<Player> getTeam() const { return team; }
	int findT(const Player& player);

}; 
