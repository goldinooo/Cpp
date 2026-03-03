#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		#define MAX_ID 8
	public:
		ContactData contacts[MAX_ID];
};

void drawtable(ContactData *contacts, int total);
void oneContact(ContactData *contact, int total);
void displayData(ContactData *contacts, int index);

#endif