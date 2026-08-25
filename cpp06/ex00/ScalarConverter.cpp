#include "ScalarConverter.hpp"
#include <cctype>
#include <cstddef>
#include <string>
#include <limits>
#include <iostream>
#include <cstdlib>
//bnaya
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

// input checkers
bool ScalarConverter::isChar(const std::string &input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	return false;
}
bool ScalarConverter::isInt(const std::string &input)
{
	size_t i = 0;

	if (input.empty())
		return false;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (i >= input.length())
        return false;
	for (; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	long long value = std::atol(input.c_str());
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		return false;
	return true;
}

bool ScalarConverter::isFloat(const std::string &input) //42.8f
{
	size_t i = 0;
	int hasPoint = 0;

	if (input.empty())
		return false;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (i >= input.length() || !isdigit(input[i]))
		return false;
	for (; i < input.length() - 1; i++)
	{
		if (input[i] == '.')
		{
			if (hasPoint)
				return false;
			hasPoint++;
		}
		else if (!isdigit(input[i]))
			return false;
	}
	if (hasPoint != 1 || input[input.length() - 1] != 'f')
		return false;
	if (!isdigit(input[input.length() - 2]))
		return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string &input) //42.8
{
	size_t i = 0;
	int hasPoint = 0;

	if (input.empty())
		return false;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (i >= input.length() || !isdigit(input[i]))
		return false;
	for (; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			if (hasPoint)
				return false;
			hasPoint++;
		}
		else if (!isdigit(input[i]))
			return false;
	}
	if (hasPoint != 1)
		return false;
	if (!isdigit(input[input.length() - 1]))
		return false;
	return true;
}

bool ScalarConverter::isSpecial(const std::string &input)
{
	return (input == "nan" || input == "+inf" || input == "-inf" ||
			input == "nanf" || input == "+inff" || input == "-inff");
}

// print functions
void ScalarConverter::printFromChar(char value)
{
	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::printFromInt(int value)
{
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::printFromFloat(float value)
{
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value == static_cast<int>(value))
		std::cout << "float: " << value << ".0f" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;
	if (value == static_cast<int>(value))
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printFromDouble(double value)
{
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<unsigned char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    if (value == static_cast<int>(value))
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

    if (value == static_cast<int>(value))
        std::cout << "double: " << value << ".0" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

void ScalarConverter::printFromSpecial(const std::string &input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

//boss function
void ScalarConverter::convert(const std::string &input)
{
	if (isSpecial(input))
	{
		printFromSpecial(input);
		return;
	}
	else if (isChar(input))
	{
		char value = input[1];
		printFromChar(value);
		return;
	}
	else if (isInt(input))
	{
		long long value = std::strtoll(input.c_str(), NULL, 10);
		printFromInt(static_cast<int>(value));
		return;
	}
	else if (isFloat(input))
	{
		float value = std::strtof(input.c_str(), NULL);
		printFromFloat(value);
		return;
	}
	else if (isDouble(input))
	{
		double value = std::strtod(input.c_str(), NULL);
		printFromDouble(value);
		return;
	}
	else
	{
		std::cout << "Error: Invalid input" << std::endl;
	}
}