#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
class Writer
{
	std::string name;
	std::string expertise;
public:
	Writer() {}
	Writer(std::string name, std::string ex) :name(name), expertise(ex) {};
	std::string getName() { return this->name; }
	std::string getExpertise() { return this->expertise; }
	friend std::ostream&operator<<(std::ostream&os, Writer&w);
	friend std::istream&operator >> (std::istream&is, Writer&w);
	~Writer();
};
