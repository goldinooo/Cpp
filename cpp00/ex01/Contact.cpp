#include "Contact.hpp"
#include <cstdio>

ContactData Contact::addcontact(ContactData contact)
{
	std::system("clear");
	std::cout << "**********_Saving_Contact_***********" << std::endl;
	sleep(1);
	contact.first__name = GetLineFromUser("Please Insert First Name : ");
	while (checkinput(contact.first__name) == false)
		contact.first__name = GetLineFromUser("Invalid input, try again : ");
	std::system("clear");
	contact.last__name = GetLineFromUser("Please Insert Last Name : ");
	while (checkinput(contact.last__name) == false)
		contact.last__name = GetLineFromUser("Invalid input, try again : ");
	std::system("clear");
	contact.nick__name = GetLineFromUser("Please Insert Nick Name : ");
	while (checkinput(contact.nick__name) == false)
		contact.nick__name = GetLineFromUser("Invalid input, try again : ");
	std::system("clear");
	contact.phone__number = GetLineFromUser("Please Insert Phone Number : ");
	while (checkinput(contact.phone__number) == false)
		contact.phone__number = GetLineFromUser("Invalid input, try again : ");
	std::system("clear");
	contact.darkest_secret = GetLineFromUser("Please Insert darkest sercret 😱 : ");
	while (checkinput(contact.darkest_secret) == false)
		contact.darkest_secret = GetLineFromUser("Invalid input, try again : ");
	std::system("clear");
	std::cout << "*********✅_Contact_Saved_✅**********" << std::endl;
	sleep(1);
	return contact;
}