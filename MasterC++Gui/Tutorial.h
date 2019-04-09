#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Duration
{
private:
	double minutes;
	double seconds;
public:
	Duration() : minutes(0), seconds(0) {}
	Duration(double min, double sec) : minutes(min), seconds(sec) {}

	double getMinutes() const { return minutes; }
	double getSeconds() const { return seconds; }

};



class Tutorial
{
private:
	std::string title;
	std::string presenter;
	Duration duration;
	int nrLikes;
	std::string link;
public:
	static int objectCount;
	Tutorial();
	~Tutorial();
	Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int nrLikes, const std::string& link);


	std::string getTitle() const { return title; }
	std::string getPresenter() const { return presenter; }
	Duration getDuration() const { return duration; }
	int getNrLikes() const { return nrLikes; }
	std::string getLink() const { return link; }
	void play();

	friend std::istream& operator>>(std::istream& is, Tutorial& s);
	friend std::ostream& operator<<(std::ostream& os, const Tutorial& s);
};

