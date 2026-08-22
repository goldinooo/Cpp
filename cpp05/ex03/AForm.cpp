#include "AForm.hpp"

AForm::AForm() : name("Default"), is_signed(false), sign_grade(150), exec_grade(150) {}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {}

AForm::AForm(const AForm& oth) : name(oth.name), is_signed(oth.is_signed), sign_grade(oth.sign_grade), exec_grade(oth.exec_grade) {}

AForm &AForm::operator=(const AForm& oth)
{
	if (this != &oth)
	{
		// name is const, so we can't assign it
		is_signed = oth.is_signed;
	}
	return *this;
}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if(bureaucrat.getGrade() > this->get_Sign_Grade())
		throw AForm::GradeTooLowException();
	else if (!this->get_is_Signed()) {
		this->is_signed = true;
		std::cout << this->getName() << " Form was signed by " << bureaucrat.getName() << std::endl;
	}
	else {
		std::cout << this->getName() << " Form is already signed" << std::endl;
	}
}

std::string AForm::getName() const {
	return name;
}

bool AForm::get_is_Signed() const {
	return is_signed;
}

int AForm::get_Sign_Grade() const {
	return sign_grade;
}

int AForm::get_Exec_Grade() const {
	return exec_grade;
}

void AForm::set_is_Signed(bool is_signed) {
	this->is_signed = is_signed;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (is_signed == false)
		throw AForm::IsNotSignedException();
	if (executor.getGrade() > exec_grade)
		throw AForm::GradeTooLowException();
	exec_action();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm: Grade too low";
}

const char* AForm::IsNotSignedException::what() const throw() {
	return "AForm: Form is not signed and cannot be executed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm: " << form.getName() << " is signed: " << form.get_is_Signed()
	   << " sign grade: " << form.get_Sign_Grade() << ", execute grade: " << form.get_Exec_Grade() << std::endl;
	return os;
}