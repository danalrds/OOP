#pragma once
#include <Windows.h>
#include <shellapi.h>
#include <string>
class Character
{
private:
	std::string name;
	int damage;
	int strength;
	std::string type;
public:
	Character(const std::string _name, const int _damage, const int _strength,const std::string _type);
	 ~Character();
	std::string getName() const { return name; }
	std::string getType() const { return type; }
	int getDamage() const { return damage; }
	int getStrength() const { return strength; }
	//virtual void strike() const = 0;    
};

class God :public Character
{
public:
	God(const std::string _name, const int _damage, const int _strength, const std::string _type);
	~God();
     
     //void strike() const override;
};
class SuperH :public Character
{
public:
	SuperH(const std::string _name, const int _damage, const int _strength, const std::string _type);
	~SuperH();
	
	//void strike() const override;
};