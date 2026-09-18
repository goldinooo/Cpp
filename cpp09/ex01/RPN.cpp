#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <cstdlib>

RPN::RPN() {}
RPN::RPN(const RPN &other) : _input(other._input) {}
RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        _input = other._input;
    }
    return *this;
}
RPN::~RPN() {}

static bool isOperator(const std::string &token) {
    return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

static bool isNumber(const std::string &token) {
    if (token.empty())
        return false;
    for (std::string::size_type i = 0; i < token.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(token[i])))
            return false;
    }
    return true;
}

int RPN::calculate(const std::string &expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isNumber(token)) {
            stack.push(std::atoi(token.c_str()));
        }
        else if (isOperator(token)) {
            if (stack.size() < 2)
                throw std::runtime_error("Invalid expression");
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Division by zero");
                    stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Invalid expression");
            }
        }
        else {
            throw std::runtime_error("Invalid expression");
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Invalid expression");
    return stack.top();
}