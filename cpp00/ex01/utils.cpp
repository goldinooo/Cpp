#include "Contact.hpp"

static std::string trimSpaces(std::string data) // trim leading and trailing whitespace
{
	size_t start = 0;
	while (start < data.size() && std::isspace(static_cast<unsigned char>(data[start])))
		++start;

	size_t end = data.size();
	while (end > start && std::isspace(static_cast<unsigned char>(data[end - 1])))
		--end;

	return data.substr(start, end - start);
}

std::string GetLineFromUser(std::string prompt)
{
	std::cout << prompt;
	std::string data;
	std::getline(std::cin, data);
	return trimSpaces(data);
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