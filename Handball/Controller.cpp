#include "Controller.h"
using namespace std;

void Controller::addPlayer(const Player& player)
{
	int pos;
	pos = this->repo.find(player);
	if (pos == -1)
	{
		this->repo.add(player);
		cout << "Player succesfully added! " << endl;
	}
	else
		cout << "Already exists!" << endl;
}
void Controller::sortPlayers()
{
	std::vector<Player> lista = this->getRepo().getPlayers();
	bool ok;
	ok = true;
	while (ok == true)
	{
		ok = false;
		for (int i = 0; i < lista.size() -1; i++)
			if (lista[i].getGoals() < lista[i+1].getGoals())
			{
				Player aux = lista[i];
				lista[i] = lista[i + 1];
				lista[i + 1] = aux;
				ok = true;
			}
	}
	for (int i = 0; i < lista.size(); i++)
	{
		Player p = lista[i];
		cout << p.getName() << " " << p.getCountry() << " " << p.getGoals() << endl;
	}
}
void Controller::list()
{
	std::vector<Player> lista = this->getRepo().getPlayers();
	for (int i = 0; i < lista.size(); i++)
	{
		Player p = lista[i];
		cout << p.getName() << " " << p.getCountry() << " " << p.getGoals() << endl;
	}
}

int Controller::count(const std::string& country)
{
	int s = 0;
	std::vector<Player> lista = this->getTeamC().getTeam();
	for (int i = 0; i < lista.size(); i++)
	{
		Player p = lista[i];
		if (p.getCountry() == country)			
			s = s + p.getGoals();
	}
	return s;
}

void Controller::addTeam(const Player& player)
{
	int pos;
	pos = this->theteam.findT(player);
	if (pos == -1)
	{
		this->theteam.addT(player);
		cout << "Player succesfully added! " << endl;
	}
	else
		cout << "Already exists!" << endl;
}