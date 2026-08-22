#pragma once

#include "AForm.hpp"
#include <string>

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern& oth);
        Intern operator=(const Intern& oth);
        ~Intern();

        AForm *makeForm(const std::string form, const std::string target);
};