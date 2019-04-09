#include "Controller.h"
using namespace std;

void Controller::addTrip(const Trip& excursie)
{
	int pos;
	pos = this->repo.findTrip(excursie.getDest(),excursie.getDays());
	if (pos == -1)
		this->repo.add(excursie);
	else
		cout << "Trip is already in list!" << endl;
}

void Controller::removeTrip(const Trip& excursie)
{
	int pos;
	pos = this->repo.findTrip(excursie.getDest(),excursie.getDays());
	if (pos != -1)
		this->repo.remove(pos);
	if (pos==-1)
		cout << "Inexistent trip!" << endl;
}

void Controller::updateTrip(const Trip& excursie, const Trip& excursienew)
{
	int pos;
	pos = this->repo.findTrip(excursie.getDest(),excursie.getDays());
	if (pos != -1)
		this->repo.update(pos,excursienew);
	else
		cout << "Inexistent trip!" << endl;
}

void Controller::list()
{
	std::vector<Trip> trips = this->getRepo().getTrips();
	for (int i = 0; i < trips.size(); i++)
	{
		Trip ex = trips[i];
		std::string str;
		str = ex.getDest();
		cout <<ex.getDest()<<" "<< ex.getDays()<<" "<<ex.getPrice()<<endl;
	}
}
/*
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
*/