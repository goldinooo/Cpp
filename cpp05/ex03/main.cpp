#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    std::cout << "\033[33m" << std::endl << "Test ex03" << "\033[0m" << std::endl;

    Intern someRandomIntern;

    std::cout << "\033[33m" << std::endl << "Test ex03 ShrubberyCreationForm" << "\033[0m" << std::endl;
    Bureaucrat Mr_Shrubby("Mr_Shrubby", 130);
    AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
    if (shrubbery)
    {
        std::cout << *shrubbery;
        Mr_Shrubby.signForm(*shrubbery);
        std::cout << *shrubbery;
        Mr_Shrubby.executeForm(*shrubbery);
        delete shrubbery;
    }
    std::cout << std::endl;

    std::cout << "\033[33m" << std::endl << "Test ex03 RobotomyRequestForm" << "\033[0m" << std::endl;
    Bureaucrat Mr_Robo("Mr_Robo", 45);
    AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robotomy)
    {
        Mr_Robo.executeForm(*robotomy);
        Mr_Robo.signForm(*robotomy);
        Mr_Robo.executeForm(*robotomy);
        Mr_Robo.executeForm(*robotomy);
        Mr_Robo.executeForm(*robotomy);
        delete robotomy;
    }
    std::cout << std::endl;

    std::cout << "\033[33m" << std::endl << "Test ex03 PresidentialPardonForm" << "\033[0m" << std::endl;
    Bureaucrat Mr_President("Mr_President", 5);
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (pardon)
    {
        Mr_Robo.executeForm(*pardon);
        Mr_Robo.signForm(*pardon);

        Mr_President.executeForm(*pardon);
        Mr_President.signForm(*pardon);
        Mr_President.executeForm(*pardon);
        delete pardon;
    }
    std::cout << std::endl;

    std::cout << "\033[33m" << std::endl << "Test ex03 Invalid Form" << "\033[0m" << std::endl;
    AForm* invalid = someRandomIntern.makeForm("invalid form", "target");
    if (invalid)
        delete invalid;

    return (0);
}