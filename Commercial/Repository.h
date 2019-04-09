#pragma once
#include "Commercial.h"

class Repository
{
private:
	std::vector<Commercial> commercials;
public:
	Repository() {};
	void add(const Commercial& comm);
	void remove(const int pos);
	void update(const int pos, const Commercial& comm);
	int findComm(const std::string& link);
	std::vector<Commercial> getCommercials() const { return commercials; }

};
