#include "Contact.hpp"
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ostream>

std::string GetLineFromUser(std::string prompt)
{
	std::cout << prompt;
	std::string data;
	std::getline(std::cin, data);
	return data;
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