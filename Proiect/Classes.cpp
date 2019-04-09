#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Classes.h"
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

istream & operator>>(istream & is, Question & q)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;
	q.id = stoi(tokens[0]);
	q.text = tokens[1];
	q.correct = tokens[2];
	q.score = stoi(tokens[3]);
	return is;

}
ostream & operator<<(ostream & os, Question& q)
{
	os << q.id << "," << q.text <<","<<q.correct<<","<<q.score<< "\n";
	return os;
}


istream & operator>>(istream & is, Participant & p)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 2)
		return is;
	p.name = tokens[0];
	p.score = stoi(tokens[1]);
	return is;

}
ostream & operator<<(ostream & os, Participant& p)
{
	os << p.name << "," << p.score << "\n";
	return os;
}