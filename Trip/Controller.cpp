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
