#include "Idea.h"

std::ostream & operator<<(std::ostream & os, Idea & d)
{
	os << d.getDescription() << ";" << d.getStatus() << ";" << d.getCreator() << ";" << std::to_string(d.getAct()) << std::endl;
	return os;
}

std::istream & operator >> (std::istream & is, Idea & d)
{
	std::string line;
	std::getline(is, line);
	std::stringstream ss(line);
	std::vector<std::string>tokens;
	std::string token;
	while (std::getline(ss, token, ';'))tokens.push_back(token);
	if (tokens.size() != 4)return is;
	d.description = tokens[0];
	d.status = tokens[1];
	d.creator = tokens[2];
	d.act = atoi(tokens[3].c_str());
	return is;
}

bool Idea::operator<(Idea & d)
{

	if (this->act< d.act)return true;
	if (this->act > d.act)return false;
	else (this->creator < d.creator);

}
