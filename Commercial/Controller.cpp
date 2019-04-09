#include "Controller.h"
using namespace std;

void Controller::addComm(const Commercial& comm)
{
	int pos;
	pos = this->repo.findComm(comm.getLink());
	if (pos == -1)
		this->repo.add(comm);
	if (pos!=-1)
		cout << "Already in list!"<<endl;
}

void Controller::removeComm(const Commercial& comm)
{
	int pos;
	pos = this->repo.findComm(comm.getLink());
	if (pos != -1)
		this->repo.remove(pos);
	if (pos == -1)
		cout << "Does not exist!!" << endl;
}

void Controller::updateComm(const Commercial& comm, const Commercial& newcomm)
{
	int pos;
	pos = this->repo.findComm(comm.getLink());
	if (pos != -1)
		this->repo.update(pos,newcomm);
	if (pos == -1)
		cout << "Does not exist!!" << endl;
}
void Controller::listAll()
{
	std::vector<Commercial> commers = this->getRepo().getCommercials();
	for (int i = 0; i < commers.size(); i++)
	{
		Commercial com = commers[i];
		cout << com.getName() << " " << com.getLink() << " " << com.getDuration() << endl;
	}
}
