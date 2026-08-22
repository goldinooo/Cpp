#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), sign_grade(150), exec_grade(150) {}
Form::Form(const std::string name, const int sign_grade, const int exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {}
Form::Form(const Form& oth) : name(oth.name), is_signed(oth.is_signed), sign_grade(oth.sign_grade), exec_grade(oth.exec_grade) {}

Form& Form::operator=(const Form& oth) {
	if (this != &oth) {
		is_signed = oth.is_signed;
	}
	return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if(bureaucrat.getGrade() > this->get_Sign_Grade())
		throw Form::GradeTooLowException();
	else if (!this->get_is_Signed()) {
		this->is_signed = true;
		std::cout << this->getName() << " Form was signed by " << bureaucrat.getName() << std::endl;
	}
	else {
		std::cout << this->getName() << " Form is already signed" << std::endl;
	}
}

std::string Form::getName() const {
	return name;
}

bool Form::get_is_Signed() const {
	return is_signed;
}

int Form::get_Sign_Grade() const {
	return sign_grade;
}

int Form::get_Exec_Grade() const {
	return exec_grade;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName() << " is signed: " << form.get_is_Signed()
	   << " sign grade: " << form.get_Sign_Grade() << ", execute grade: " << form.get_Exec_Grade() << std::endl;
	return os;
}