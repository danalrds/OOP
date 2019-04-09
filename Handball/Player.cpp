#include "Player.h"

Player::Player()
{
	this->name = "";
	this->country = "";
	this->goals = 0;
}

Player::~Player()
{}

Player::Player(const std::string& name, const std::string& country, const int goals)
{
	this->name = name;
	this->country = country;
	this->goals = goals;
}
