#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();
	void addTutorialToRepo();
	void deleteTutorialRepo();
	void updateTutorialRepo();
	void displayAllTutorialsRepo();	

	void addTutorialToPlaylist();
	void deleteFromPlaylist();
	void displayPlaylist();
	void showPlaylistByPresenter();
};

