#include "Contact.hpp"

static std::string trimspace(std::string data) // this is wrong
{
	int start = 0;
	int end = data.size();
	while (start < end && std::isspace(data.at(start)))
		start++;
	while (end > 0 && std::isspace(data.at(end - 1)))
		end--;
	return data.substr(start, end - start);
}

std::string GetLineFromUser(std::string prompt)
{
	std::cout << prompt;
	std::string data;
	std::getline(std::cin, data);
	return trimspace(data);
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