#pragma once

#include <iostream>
#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string 	name;
		bool 				is_signed;
		const int 			sign_grade;
		const int 			exec_grade;
	public:
		//bnaya
		Form();
		Form(const std::string name, const int sign_grade, const int exec_grade);
		Form(const Form& oth);
		Form &operator=(const Form& oth);
		~Form();

		//functions
		void beSigned(Bureaucrat& bureaucrat);

		//getters
		std::string getName() const;
		bool get_is_Signed() const;
		int get_Sign_Grade() const;
		int get_Exec_Grade() const;


		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);