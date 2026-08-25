#pragma once


#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void convert(const std::string &input);

		//scalaesr types bool
		static bool isChar(const std::string &input);
		static bool isInt(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isDouble(const std::string &input);
		static bool isSpecial(const std::string &input);

		//print functions
		static void printFromChar(char value);
		static void printFromInt(int value);
		static void printFromFloat(float value);	
		static void printFromDouble(double value);
		static void printFromSpecial(const std::string &input);
};