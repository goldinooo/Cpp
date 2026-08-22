#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string s_name, int s_grade) : name(s_name) {
	if (s_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (s_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = s_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& oth) : name(oth.name), grade(oth.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& oth) {
	if (this != &oth) {
		// name is const so we can't assign to it
		grade = oth.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incr_grade() {
	if (grade == 1)
		throw GradeTooHighException();
	else if(grade > 1)
		grade--;
}

void Bureaucrat::decr_grade() {
	if (grade == 150)
		throw GradeTooLowException();
	else if(grade < 150)
		grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} 
	catch (const std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	} 
	catch (const std::exception& e) {
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}