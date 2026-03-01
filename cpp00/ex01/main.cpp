#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string output;
	int id = 0;
	std::system("clear");
	for(;;){
		output = GetLineFromUser("An Awesome Phone_Book at your service :\n[*]ADD :\n[*]SEARCH :\n[*]EXIT :\n -------------> ");
		if (output == "ADD")
		{
			std::system("clear");
			pb.contacts[id % 8] = addcontact(pb.contacts[id % 8]);
			id += 1;
		}
		if(output == "SEARCH")
		{
			int total;
			if (id < 8)
				total = id;
			else
				total = 8;
			std::system("clear");
			drawtable(pb.contacts, total);
		}
		else if (output == "EXIT")
		{
			std::system("clear");
			std::cout << "An Awesome Phone_Book Was Happy To Have You" << std::endl;
			std::system("clear");
			sleep(1);
			std::cout << "bye bye" << std::endl;
			sleep(1);
			std::system("clear");
		}
	}
	return 0;
}