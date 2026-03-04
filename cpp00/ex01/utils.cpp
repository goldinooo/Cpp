#include "Contact.hpp"

static std::string trim(std::string data) // this is wrong
{
	std::string newstr = data;
	int i = 0;
	while(newstr.at(i))
	{
		if(std::isspace(newstr.at(i)))
			i++;
	}
	return newstr;
}

std::string GetLineFromUser(std::string prompt)
{
	std::cout << prompt;
	std::string data;
	std::getline(std::cin, data);
	return trim(data);
}

bool checkinput(std::string s)
{
	if(s.empty())
		return false;
	for(size_t i = 0; i < s.size(); i++)
	{
		if(std::isalpha(s.at(i)))
			return true;
		if(std::isdigit(s.at(i)))
			return true;
	}
	return false;
}