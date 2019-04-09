#include "Tests.h"
#include <assert.h>
#include <vector>
#include "Repository.h"
#include "PlayList.h"
#include "Controller.h"

using namespace std;

void Tests::testSong()
{
	Duration d{ 4, 54 };
	Song s{ "Ed Sheeran", "I see fire", d, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	assert(s.getArtist() == "Ed Sheeran");
	assert(s.getTitle() == "I see fire");
	assert(s.getSource() == "https://www.youtube.com/watch?v=2fngvQS_PmQ");
	assert(s.getDuration().getMinutes() == 4);
	assert(s.getDuration().getSeconds() == 54);
}

void Tests::testRepository()
{
	Repository repo{};
	Song s{ "Ed Sheeran", "I see fire", Duration{ 4, 54 }, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	repo.addSong(s);
	Song res = repo.findByArtistAndTitle("Ed Sheeran", "I see fire");
	assert(res.getTitle() == s.getTitle() && res.getArtist() == s.getArtist());
	res = repo.findByArtistAndTitle("Ed Sheeran", "");
	assert(res.getArtist() == "");

	vector<Song> songs = repo.getSongs();
	assert(songs.size() == 1);
}

void Tests::testPlaylist()
{
	PlayList playList{};
	Song s1{ "Ed Sheeran", "I see fire", Duration{ 4, 54 }, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	Song s2{ "Two Steps From Hell", "Heart of Courage", Duration{ 8, 12 }, "https://www.youtube.com/watch?v=XYKUeZQbMF0" };
	playList.add(s1);
	playList.add(s2);

	assert(playList.isEmpty() == false);

	/*playList.play();
	assert(playList.getCurrentSong().getArtist() == "Ed Sheeran");
	playList.next();
	assert(playList.getCurrentSong().getArtist() == "Two Steps From Hell");
	playList.next();
	assert(playList.getCurrentSong().getArtist() == "Ed Sheeran");*/
}

void Tests::testController()
{
	Repository repo{};
	Controller ctrl{ repo };
	ctrl.addSongToRepository("Ed Sheeran", "I see fire", 4, 54, "https://www.youtube.com/watch?v=2fngvQS_PmQ");
	ctrl.addSongToRepository("Two Steps From Hell", "Heart of Courage", 8, 12, "https://www.youtube.com/watch?v=XYKUeZQbMF0");
	Song s{ "Ed Sheeran", "I see fire", Duration{ 4, 54 }, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	ctrl.addSongToPlaylist(s);
	ctrl.addAllSongsByArtistToPlaylist("Two Steps From Hell");

	assert(ctrl.getRepo().getSongs().size() == 2);
	
	PlayList list = ctrl.getPlaylist();
	assert(list.isEmpty() == false);
	assert(list.getCurrentSong().getArtist() == "Ed Sheeran");

	// the following lines were commented to avoid playing the songs at each execution of the application
	//ctrl.startPlaylist();
	//ctrl.nextSongPlaylist();	
}

void Tests::testAll()
{
	testSong();
	testRepository();
	testPlaylist();
	testController();
}
