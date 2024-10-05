#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called!\n";
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called!\n";
}

ScalarConverter::ScalarConverter(ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter &obj)
{
    (void)obj;
	return *this;
}

std::string ScalarConverter::intToChar(int value) {
    if (value >= 32 && value <= 126) {
        std::stringstream  ss;
        ss << "'" << static_cast<char>(value) << "'";
        return ss.str();
    }
    return "Non displayable";
}

std::string ScalarConverter::floatDoubleToChar(float value) {
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
        return intToChar(static_cast<int>(value));
    }
    return "impossible";
}

std::string ScalarConverter::floatDoubleToInt(float value) {
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
        std::stringstream  ss;
        ss << static_cast<int>(value);
        return ss.str();
    }
    return "impossible";
}

void ScalarConverter::convert(const std::string &literal)
{
    char c;
	int i;
	float f;
	double d;

    // checking nan, +inf, -inf ...
    if (literal == "nan"  || literal == "inf" || literal == "+inf" || literal == "-inf")
    {
        std::cout << "The data type is: literals\n";
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal + "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    } 
    else if (literal == "nanf" || literal == "inff" || literal == "+inff" || literal == "-inff")
    {
        std::cout << "The data type is: literals\n";
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        return;

    }
    // char
	if (literal.length() == 1 && !isdigit(literal[0]))
	{
        c = literal[0];
        std::cout << "The data type is: char\n";
		std::cout << "char: " << c << '\n';
		std::cout << "int: " << static_cast<int>(c) << '\n';
		std::cout << "float: " << std::fixed << std::setprecision(3) << static_cast<float>(c) << "f" << '\n';
		std::cout << "double: " << std::fixed << std::setprecision(3) << static_cast<double>(c) << '\n';
		return;
	}
    // converting to int
	errno = 0;
	char *endChecker;
    long temp = std::strtol(literal.c_str(), &endChecker, 10);
	if (errno == 0 && *endChecker == '\0')
	{
        std::cout << "The data type is: int\n";
        if (temp > INT_MAX || temp < INT_MIN) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
        } else {
            i = static_cast<int>(temp);
            std::cout << "char: " << intToChar(i) << '\n';
            std::cout << "int: " << i << '\n';
        }
        std::cout << "float: " << std::fixed << std::setprecision(3) << static_cast<float>(temp) << "f" << '\n';
        std::cout << "double: " << std::fixed << std::setprecision(3) << static_cast<double>(temp) << '\n';
        return;
	}
    // converting to double
    errno = 0;
    d = std::strtod(literal.c_str(), &endChecker);
    if (errno == 0 && *endChecker == '\0')
    {
        std::cout << "The data type is: Double\n";
        std::cout << "char: " << floatDoubleToChar(d) << '\n';
		std::cout << "int: " << floatDoubleToInt(d) << '\n';
		std::cout << "float: " << std::fixed << std::setprecision(3) << static_cast<float>(d) << "f" << '\n';
		std::cout << "double: " << std::fixed << std::setprecision(3) << d << '\n';
		return;
    }
    // converting to float
    errno = 0;
    std::string modifiedLiteral = literal;
    if (modifiedLiteral[modifiedLiteral.length() - 1] == 'f' || 
        modifiedLiteral[modifiedLiteral.length() - 1] == 'F')
            modifiedLiteral.resize(modifiedLiteral.length() - 1);
    f = std::strtof(modifiedLiteral.c_str(), &endChecker);
    if (errno == 0 && *endChecker == '\0')
    {
        std::cout << "The data type is: Float\n";
        std::cout << "char: " << floatDoubleToChar(f) << '\n';
		std::cout << "int: " << floatDoubleToInt(f) << '\n';
		std::cout << "float: " << std::fixed << std::setprecision(3) << f << "f" << '\n';
		std::cout << "double: " << std::fixed << std::setprecision(3) << static_cast<double>(f) << '\n';
		return;
    }


    std::cerr << "Error: Invaalid Literal.\n";
}
