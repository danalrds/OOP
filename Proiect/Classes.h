#pragma once
#include <string>
class Question
{
private:
	int id;
	std::string text;
	std::string correct;
	int score;
public:
	Question(int id, std::string text, std::string correct, int score) : id{ id }, text{ text }, correct{ correct }, score{ score } {}
	~Question() {}
	Question() {}
	int getId() const { return this->id; }
	std::string getText() const { return this->text; }
	std::string getCorrect() const { return this->correct; }
	int getScore() const { return this->score; }
	
	friend std::ostream& operator<<(std::ostream&os, Question&w);
	friend std::istream& operator>>(std::istream&is, Question&w);

};

class Participant
{
private:
	std::string name;
	int score;
public:
	Participant() {}
	Participant(std::string name, int score) : name{ name }, score{ score } {}
	~Participant() {}
	std::string getName() const { return this->name; }
	int getScore() const { return score; }
	friend std::ostream& operator<<(std::ostream&os, Participant&p);
	friend std::istream& operator>>(std::istream&is, Participant&p);
};