#pragma once

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm {
	private:
		const std::string 	name;
		bool 				is_signed;
		const int 			sign_grade;
		const int 			exec_grade;
		virtual void exec_action() const = 0;
	public:
		//bnaya
		AForm();
		AForm(const std::string name, const int sign_grade, const int exec_grade);
		AForm(const AForm& oth);
		AForm &operator=(const AForm& oth);
		~AForm();

		//functions
		void beSigned(Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;

		//getters
		std::string getName() const;
		bool get_is_Signed() const;
		int get_Sign_Grade() const;
		int get_Exec_Grade() const;

		//setters
		void set_is_Signed(bool is_signed);

		//exceptions
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
		class IsNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);