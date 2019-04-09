#pragma once
#include <string>
class User
{
private:
	std::string name;
	std::string type;
public:
	User(std::string name, std::string type) : name{ name }, type{ type } {}
	~User() {}
	User() {}
	std::string getName() const { return name; }
	std::string getType() const { return type; }
	friend std::ostream& operator<<(std::ostream&os, User&w);
	friend std::istream& operator>>(std::istream&is, User&w);
};

class Issue
{
private:
	std::string desc;
	std::string status;
	std::string reporter;
	std::string solver;
public:
	Issue() {}
	std::string getDesc() const { return desc; }
	std::string getStatus() const { return status; }
	std::string getReporter() const { return reporter; }
	std::string getSolver() const { return solver; }
	Issue(std::string desc, std::string status, std::string reporter, std::string solver) :
		desc{ desc }, status{ status }, reporter{ reporter }, solver{ solver } {}
	~Issue() {}
	friend std::ostream& operator<<(std::ostream&os, Issue&w);
	friend std::istream& operator>>(std::istream&is, Issue&w);
	void setStatus(std::string nou)
	{
		this->status = nou;
	}
	void setSolver(std::string nou)
	{
		this->solver = nou;
	}
};