#include "Validator.h"
using namespace std;

Exception::Exception(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> Exception:: getErrors() const 
{
	return this->errors;
}

void Validator::validate(const Tutorial& t)
{
	std::vector<std::string> errors;
	if (t.getTitle().size() < 1)
		errors.push_back("The title name cannot be less than 1 character!\n");
	if (!isupper(t.getPresenter()[0]))
		errors.push_back(string("The name of the presenter must start with a capital letter!\n"));
	if (t.getDuration().getMinutes() == 0 && t.getDuration().getSeconds() == 0)
		errors.push_back(string("The duration cannot be 0!\n"));
	// search for "www" or "http" at the beginning of the source string
	size_t posWww = t.getLink().find("www");
	size_t posHttp = t.getLink().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"\n");

	if (errors.size() > 0)
		throw Exception(errors);

}