#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		//bnaya
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& oth);
		Bureaucrat &operator=(const Bureaucrat& oth);
		~Bureaucrat();

		//getters
		std::string getName() const;
		int			getGrade() const;

		//setters
		void	incr_grade();
		void	decr_grade();

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

		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
};