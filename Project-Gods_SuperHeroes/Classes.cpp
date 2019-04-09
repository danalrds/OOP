#include "Classes.h"
#include <iostream>


Character::Character(const std::string _name, const int _damage, const int _strength,const std::string _type) : name{ _name }, damage{ _damage }, 
strength{ _strength }, type{_type}
{}
Character::~Character()
{}
God::God(const std::string _name, const int _damage, const int _strength, const std::string _type) : Character{_name,_damage,_strength,_type}
{}
God::~God()
{}
SuperH::SuperH(const std::string _name, const int _damage, const int _strength, const std::string _type) : Character{ _name,_damage,
_strength,_type}
{}
SuperH::~SuperH()
{}

