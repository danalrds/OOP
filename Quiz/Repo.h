#pragma once
#include "Classes.h"
#include <vector>
class Repo
{
private:
	std::vector<Question> questions;
	std::vector<Participant> participants;	
public:
	Repo();
	~Repo();
	std::vector<Question> getQ() const { return questions; }
	std::vector<Participant> getP() const { return participants; }
	void readFromFileQ();
	void readFromFileP();
	void add(Question q);
	int find(int id);
	void printToFile();
	int findPar(std::string name);
	void update(std::string name, int score);
 };

class A
{
public:
	std::string name;
	std::vector<int>ans;
public:
	std::string getName() const { return name; }
	A(std::string name) :name{ name } {}
	~A() {}	
};