#pragma once

#include <string>
#include <iostream>

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern& oth);
        Intern &operator=(const Intern& oth);
        ~Intern();

        AForm *makeForm(const std::string form, const std::string target);
};