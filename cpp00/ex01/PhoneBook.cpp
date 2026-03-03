#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string truncate(std::string s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

static void drawline()
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

static void drawrow(std::string c1, std::string c2, std::string c3, std::string c4)
{
	std::cout << "|" << std::setw(10) << truncate(c1);
	std::cout << "|" << std::setw(10) << truncate(c2);
	std::cout << "|" << std::setw(10) << truncate(c3);
	std::cout << "|" << std::setw(10) << truncate(c4);
	std::cout << "|" << std::endl;
}

void drawtable(ContactData *contacts, int total)
{
	std::string index;

	drawline();
	drawrow("Index", "First Name", "Last Name", "Nickname");
	drawline();
	for (int i = 0; i < total; i++)
	{
		index = '0' + i;
		drawrow(index, contacts[i].first__name, contacts[i].last__name, contacts[i].nick__name);
	}
	drawline();
}
void displayData(ContactData *contacts, int index)
{
	std::cout << contacts[index].first__name << std::endl;
	std::cout << contacts[index].last__name << std::endl;
	std::cout << contacts[index].nick__name << std::endl;
	std::cout << contacts[index].phone__number << std::endl;
	std::cout << contacts[index].darkest_secret << std::endl;
}

void oneContact(ContactData *contact, int total)
{
	std::string id;
	id = GetLineFromUser("Please Choose An Index Of The Contact To Display :\t");
	for(int i = 0; id[i]; i++)
	{
		if(!std::isdigit(id[i]))
		{
			std::cout << "ERROR";
			return ;
		}	
	}
	int d_Id = std::atoi(id.c_str());
	if(d_Id > total || d_Id < 0)
		return;
	else
		displayData(contact, d_Id);
}