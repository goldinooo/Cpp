#include "Contact.hpp"


int main()
{
	Contact contact;
	std::string output;
	ContactData contactdata;

	for(;;){
		output = GetLineFromUser("an Awesome Phone_Book at your service :\n[*]ADD :\n[*]SEARCH :\n[*]EXIT :\n");
		if (output == "ADD")
		{
			//clear buffer
			std::cout << "**********_Saving_Contact_***********" << std::endl;
			contactdata.first__name = GetLineFromUser("Please Insert First Name :\t");
			//clear buffer
			contactdata.last__name = GetLineFromUser("Please Insert Last Name :\t");
			//clear buffer
			contactdata.nick__name = GetLineFromUser("Please Insert Nick Name :\t");
			//clear buffer
			contactdata.phone__number = GetLineFromUser("Please Insert Phone Number :\t");
			//clear buffer
			contactdata.darkest_secret = GetLineFromUser("Please Insert darkest sercret 😱 :\t");
			std::cout << "*********✅_Contact_Saved_✅**********" << std::endl;
			continue;
		}
		if(output == "SEARCH")
		{
			break;
		}
	}
	return 0;
}