#pragma once
#include "Player.h"

class Repository
{
private:
	std::vector<Player> players;
public:
	Repository() {}
	void add(const Player& player);	
	std::vector<Player> getPlayers() const { return players; }
	int find(const Player& player);

};