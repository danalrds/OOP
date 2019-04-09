#include "HTML.h"
#include <fstream>
#include <Windows.h>
#include "RepoExceptions.h"

using namespace std;

void HTMLPlaylist::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");
	f << "<!DOCTYPE html> " << endl;
	f << "<html> " << endl;
	f << "<head>  " << endl;
	f << "<title>Playlist</title>   " << endl;
	f << "</head>  " << endl;
	f << "<body>   " << endl;
	f << "<table border=\"1\">" << endl;
	f << "<tr> " << endl;
	f << "<td> Title </td>";
	f << "<td> Presenter </td> ";
	f << "<td> Duration </td> ";
	f << "<td> Nr likes </td> ";
	f << "<td> Youtube link </td> ";
	f << "</tr> " << endl;
	for (auto s : this->getTutorials())
	{
		f << "<tr> " << endl;
		f << "<td>"<< s.getTitle()<< "</td>"<<endl;
		f << "<td>" << s.getPresenter()<< "</td>"<<endl;
		f << "<td>" << s.getDuration().getMinutes()<<":"<<s.getDuration().getSeconds() << "</td>";
		f << "<td>" << s.getNrLikes() << "</td>";
		f << "<td><a href =" <<"\"" <<s.getLink()<<"\""<< ">Link</a></td>";
		//f << s;
		f << "</tr> " << endl;
	}
	f << "</table> " << endl;
	f << "</body> " << endl;
	f << "</html> " << endl;
	f.close();
}

void HTMLPlaylist::displayPlaylist() const
{
	string aux = "file:///C:/Users/diago/source/repos/MasterC++/MasterC++/" + this->filename; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
