#include "Repository.h"
using namespace std;

void Repository::add(const Trip& excursie)
{
	this->thetrips.push_back(excursie);
}

void Repository::remove(const int pos)
{
	this->thetrips.erase(this->thetrips.begin() + pos);
}

void Repository::update(const int pos, const Trip& excursie)
{
	this->thetrips[pos] = excursie;
}

int Repository::findTrip(const std::string& dest, const int days)
{	
	for (int i = 0; i < this->thetrips.size(); i++)
	{		
		Trip trip = this->thetrips[i];
		//cout << trip.getDest()<<endl;
		if (trip.getDest() == dest)
			if (trip.getDays() == days)
				return i;
	}
	return -1;
}