#include "Repository.h"



Repository::Repository()
{
}

void Repository::readIdeasFromFile(std::string fname)
{
	std::ifstream f(fname);
	if (!f.is_open())return;
	Idea d;
	while (f >> d)this->ideas.push_back(d);
}

void Repository::readWitersFromFile(std::string fname)
{
	std::ifstream f(fname);
	if (!f.is_open())return;
	Writer w;
	while (f >> w)this->writers.push_back(w);

}

void Repository::addIdea(Idea d)
{
	for (auto i : this->ideas) {
		if (d == i && d.getAct() == i.getAct())throw std::exception("duplicate idea");
	}
	this->ideas.push_back(d);
}


void Repository::updateStatuse(std::string description, int act)
{
	for (auto&d : this->ideas) {
		if (d.getDescription() == description && d.getAct() == act) {
			d.setStatus("accepted");
		}
	}
}

void Repository::updateDescription(std::string original, int act, std::string n)
{
	for (auto&d : this->ideas) {
		if (d.getDescription() == original) {

			d.setIdea(n);

		}
	}
}

Repository::~Repository()
{
}
