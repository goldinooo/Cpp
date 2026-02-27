#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstddef>
#include <string>
#include <iostream>

typedef struct {
	std::string first__name;
	std::string last__name;
	std::string nick__name;
	std::string phone__number;
	std::string darkest_secret;

} ContactData;

class Contact {
	private:
		ContactData contactinfo;
	public:
};
std::string GetLineFromUser(std::string prompt);
#endif // HEADER_HPP