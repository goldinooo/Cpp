#pragma once

#include <stdlib.h> // rand()
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
	virtual void exec_action() const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	//exception class
	class RobotomyRequestException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};
