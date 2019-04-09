#pragma once
#include "Repository.h"
#include "Team.h"

class Controller
{
private:
	Repository repo;
	Team theteam;
public:	
	Controller(const Repository& r) : repo(r) {};
	Controller(const Team& r) : theteam(r) {};
	Repository getRepo() const { return repo; }
	Team getTeamC() const { return theteam; }
	void addPlayer(const Player& player);
	void addTeam(const Player& player);
	void sortPlayers();
	int count(const std::string& country);
	void list();

};