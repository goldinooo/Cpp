#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& oth)
{
    (void)oth;
}
Intern& Intern::operator=(const Intern& oth)
{
	(void)oth;
	return *this;
}

Intern::~Intern() {}

static int InternFormIndex(std::string name)
{
	if (name == "shrubbery creation")
		return 1;
	if (name == "robotomy request")
		return 2;
	if (name == "presidential pardon")
		return 3;
	return -1;
}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
	int index = InternFormIndex(form);
	switch (index)
	{
		case 1:
			std::cout << "Intern creates " << form << std::endl;
			return new ShrubberyCreationForm(target);
		case 2:
			std::cout << "Intern creates " << form << std::endl;
			return new RobotomyRequestForm(target);
		case 3:
			std::cout << "Intern creates " << form << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Intern cannot create " << form << std::endl;
		return NULL;
	}
}
