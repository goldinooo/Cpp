#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstddef>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sstream>

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
ContactData addcontact(ContactData contact);
bool checkinput(std::string s);

#endif // HEADER_HPP