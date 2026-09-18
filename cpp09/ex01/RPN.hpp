#pragma once
#include <string>
#include <stack>
#include <exception>
#include <algorithm>
#include <ostream>
#include <iostream>

class RPN {
    private:
        std::string _input;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int calculate(const std::string &expression);
};