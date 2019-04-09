#include "Controller.h"
using namespace std;

void Controller::addSong(const Song& song)
{
	int pos;
	
	if ((song.getHeavy() < 0) || (song.getHeavy() > 100))
	{
		cout << "Heaviness must be i [0,100]" << endl;
		return;
	}
	if (song.getTitle() == "")
	{
		cout << "Empty title! " << endl;
		return;
	}
	if (song.getArtist() == "")
	{
		cout << "Empty artist! " << endl;
		return;
	}
	if (song.getDuration() <0)
	{
		cout << "Duration must > 0! " << endl;
		return;
	}
	
	pos = this->repo.find(song.getId());
	if (pos == -1)
		this->repo.add(song);
	else
		cout << "Song is already in list!" << endl;
}



void Controller::list(std::vector<Song> lista)
{	
	for (int i = 0; i < lista.size(); i++)
	{
		Song s= lista[i];	
	
		cout <<s.getId()<<" "<< s.getTitle()<<" "<<s.getArtist()<<" "<<s.getDuration()<<" "<<s.getHeavy()<<endl;
	}
}

std::vector<Song> Controller::make(const std::string& artist, const int duration)
{
	std::vector<Song> lista = this->getRepo().getSongs();
	std::vector<Song> rez;
	int i = 0;
	while (i < lista.size())
	{
		Song s = lista[i];
		if (s.getArtist() != artist)
		{
			lista.erase(lista.begin() + i);
			i = i - 1;
		}
		i = i + 1;		    

	}

	bool ok;
	ok = true;
	while (ok == true)
	{
		ok = false;
		for (int i = 0; i < lista.size() - 1; i++)
			if (lista[i].getHeavy() < lista[i + 1].getHeavy())
			{
				Song aux = lista[i];
				lista[i] = lista[i + 1];
				lista[i + 1] = aux;
				ok = true;
			}
	}
	int index = lista.size();
	int sum = 0;
	for (int i =0; i<lista.size();i++)
	{
		Song s = lista[i];
		if (sum + s.getDuration() <= duration)
		{
			sum = sum + s.getDuration();			
			rez.push_back(s);
		}
		else
			break;
	}		
	return rez;
	
}

std::vector<Song> Controller::Mix(const int duration)
{
	std::vector<Song> lista = this->getRepo().getSongs();
	std::vector<Song> songslist;
	bool ok;
	ok = true;
	while (ok == true)
	{
		ok = false;
		for (int i = 0; i < lista.size() - 1; i++)
			if (lista[i].getDuration() > lista[i + 1].getDuration())
			{
				Song aux = lista[i];
				lista[i] = lista[i + 1];
				lista[i + 1] = aux;
				ok = true;
			}		
			else if (lista[i].getDuration()== lista[i + 1].getDuration())
			{
				if (lista[i].getHeavy() < lista[i + 1].getHeavy())
				{
					Song aux = lista[i];
					lista[i] = lista[i + 1];
					lista[i + 1] = aux;
					ok = true;
				}
			}

	}
	int sum = 0;
	for (int i = 0; i<lista.size(); i++)
	{
		Song s = lista[i];
		if (sum + s.getDuration() <= duration)
		{
			sum = sum + s.getDuration();
			songslist.push_back(s);
		}
		else
			break;
	}	
	return songslist;
}







