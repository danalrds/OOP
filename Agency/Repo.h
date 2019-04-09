#pragma once
#include "Classes.h"
#include <vector>
#include <algorithm>
class Repo
{
private:
	std::vector<Offer*> offers;
public:
	Repo();
	~Repo();
	std::vector<Offer*> getOffers() const { return offers; }
	void add(Offer* offer);
	void remove(Offer* offer);
	int find(const std::string name);	
	virtual void writeToFile() const = 0;
};


class Csv:public Repo
{
private:
	std::string filename;
public:
	Csv(std::string filename);
	~Csv();	
	void writeToFile() const override;
	std::string getFile() const { return filename; }
};

class Special :public Repo
{
private:
	std::string filename;
public:
	Special(std::string filename);
	~Special();
	void writeToFile() const override ;
	std::string getFile() const { return filename; }
};
