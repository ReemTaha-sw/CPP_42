#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>    // For strtol, strtof, strtod
#include <cerrno>     // For errno
#include <cctype>     // For isdigit, isalpha, isprint
#include <limits>     // For std::numeric_limits
#include <sstream>    // For std::stringstream
#include <iomanip>	  // std::fixed

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter &copy);
		ScalarConverter &operator=(ScalarConverter &other);
		static std::string intToChar(int value);
		static std::string floatDoubleToChar(float value);
		static std::string floatDoubleToInt(float value);
	public:
		static void convert(const std::string &literal);
};

#endif
