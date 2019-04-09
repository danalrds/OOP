#pragma once
#include "Tutorial.h"

class Exception
{
private:
	std::vector<std::string> errors;

public:
	Exception(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class Validator
{
public:
	Validator() {};
	static void validate(const Tutorial& t);
};
