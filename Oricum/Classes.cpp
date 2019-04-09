#include "Classes.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> tokenize(const string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

istream & operator>>(istream & is, User & q)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 2) 
		return is;

	q.name = tokens[0];
	q.type = tokens[1];	
	return is;

}

ostream & operator<<(ostream & os, User& q)
{
	os << q.name<< "," << q.type<< "\n";
	return os;
}

///////////////////////////Issue

istream & operator>>(istream & is, Issue & q)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;

	q.desc = tokens[0];
	q.status = tokens[1];
	q.reporter =tokens[2];
	q.solver = tokens[3];
	return is;

}

ostream & operator<<(ostream & os, Issue& q)
{
	os << q.desc << "," << q.status << ","<<q.reporter<<","<<q.solver<<"\n";
	return os;
}