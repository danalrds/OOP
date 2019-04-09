#include "UI.h"
#include <Windows.h>
#include <assert.h>
using namespace std;
void tests()
{
	///requirement 1
	Repository repo{};
	Controller ctrl{ repo };
	Song s1{ 1,"Monster","Eminem",4,8.9 };
	Song s2{ 2,"River","Eminem",4,9 };
	Song s3{ 3,"Lose yourself","Eminem",50,9 };
	assert(s1.getId() == 1);
	assert(s1.getTitle() == "Monster");
	assert(s1.getArtist() == "Eminem");
	ctrl.addSong(s1);
	ctrl.addSong(s2);
	assert(ctrl.getRepo().getSongs().size() == 2);
	ctrl.addSong(s3);
	assert(ctrl.getRepo().getSongs().size() ==3);
	///requirement 2
	Song s4{ 4,"We found love","Rihanna",4,100 };
	Song s5{ 5,"The way I am","Eminem",50,12 };
	ctrl.addSong(s4);
	ctrl.addSong(s5);
	std::vector<Song> songgs = ctrl.make("Eminem",100);
	std::vector<Song> lista = ctrl.getRepo().getSongs();
	Song s = songgs[0];
	Song ss = songgs[1];	
	assert(s.getTitle() == "The way I am");
	assert(ss.getTitle() == "River");
	///requirement 3
	lista = ctrl.Mix(65);	
	assert(lista[0].getTitle() == "We found love");
	assert(lista[1].getTitle() == "River");
	assert(lista[2].getTitle() == "Monster");
	assert(lista[3].getTitle() == "The way I am");
}
int main()
{
	system("color f1");
	tests();
	Repository repo{};	
	Song s1{ 1,"Monster","Eminem",4,8.9 };
	Song s2{ 2,"River","Eminem",50,9 };
	Song s3{ 3,"Lose yourself","Eminem",4,4 };
	Song s4{ 4,"We found love","Rihanna",4,100 };
	Song s5{ 5,"The way I am","Eminem",50,12 };
	repo.add(s3);
	repo.add(s2);
	repo.add(s1);
	repo.add(s4);
	repo.add(s5);
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
	return 0;
}