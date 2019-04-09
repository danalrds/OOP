#include "Repository.h"
using namespace std;

void Repository::add(const Song& song)
{
	this->songs.push_back(song);
}


int Repository::find(const int id)
{	
	for (int i = 0; i < this->songs.size(); i++)
	{		
		Song s = this->songs[i];
		//cout << trip.getTitle()<<endl;
		if (s.getId() == id)			
				return i;
	}
	return -1;
}