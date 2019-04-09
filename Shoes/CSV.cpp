#include "CSV.h"
#include "Repo.h"
#include <iostream>
#include <fstream>
//#include <crtdbg.h>
using namespace std;
CSV::CSV(const std::string& filename)
{
	this->filename = filename;
}
CSV::~CSV()
{}
void CSV::writeToFile() const
{
	ofstream file(this->filename);		
	for (auto s : this->getShoes())
	{		
		file << s->toString();
	}
	file.close();

}
void CSV::display() const
{
	string aux = this->filename; // if the path contains spaces, we must put it inside quotations
												//ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}