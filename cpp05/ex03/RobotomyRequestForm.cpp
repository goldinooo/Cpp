#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::exec_action() const
{
	std::cout << "Drilling noises..." << std::endl;
	if (rand() % 2)
		std::cout << getName() << " has been robotomized successfully." << std::endl;
	else
		throw RobotomyRequestException();
}

const char* RobotomyRequestForm::RobotomyRequestException::what() const throw()
{
	return "RobotomyRequestForm exception";
}
