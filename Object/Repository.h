#pragma once
#include "Class.h"

class Repository
{
private:
	std::vector<Trip> thetrips;
public:
	Repository() {}
	void add(const Trip& excursie);
	void remove(const int pos);
	void update(const int pos, const Trip& excursie);
	std::vector<Trip> getTrips() const { return thetrips; }
	int findTrip(const std::string& dest, const int days);

};