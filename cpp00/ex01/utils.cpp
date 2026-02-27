#include "Contact.hpp"

std::string GetLineFromUser(std::string prompt)
{
	std::cout << prompt;
	std::string data;
	std::getline(std::cin, data);
	return data;
}
