#pragma once
#include <string>
#include <fstream>
class Question
{
private:
	int id;
	std::string text;
	std::string correct;
	int score;
public:
	Question(int id, std::string text, std::string correct, int score);
	~Question();
	Question() {}
	friend std::ostream& operator<<(std::ostream&os, Question&w);
	friend std::istream& operator>>(std::istream&is, Question&w);
	int getId() const { return id; }
	std::string getText() const { return text; }
	std::string getCorrect() const { return correct; }
	int getScore() const { return score; }

};


class Participant
{
private:
	std::string name;
	int score;	
public:	
	Participant(std::string name, int score);
	~Participant();
	Participant() {}
	std::string getName() const { return name; }
	int getScore() const { return score; }
	friend std::ostream & operator <<(std::ostream& os, Participant& p);
	friend std::istream& operator >>(std::istream& is, Participant& p);
	void setScore(int nou)
	{
		this->score = this->score+nou;
	}
};
