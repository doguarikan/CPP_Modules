#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter  &copy) {(void)copy;}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return *this;
}

void ScalarConverter::convert(std::string const& value)
{
	if (value.length() == 1 && !isdigit(value[0]))
	{
		char c = value[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	char *end;
	long intValue = std::strtol(value.c_str(), &end, 10);
	if (*end == '\0' && intValue <= INT_MAX && intValue >= INT_MIN)
	{
		int i = static_cast<int>(intValue);
		if (i >= 32 && i <= 126)
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else if (i >= 0 && i <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
		return;
	}

	double doubleValue = std::strtod(value.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
	{
		float f = static_cast<float>(doubleValue);
		if (f >= 32 && f <= 126)
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else if (f >= 0 && f <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (f >= INT_MIN && f <= INT_MAX)
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return;
	}

	if (*end == '\0')
	{
		if (doubleValue >= 32 && doubleValue <= 126)
			std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
		else if (doubleValue >= 0 && doubleValue <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (doubleValue >= INT_MIN && doubleValue <= INT_MAX)
			std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
		std::cout << "double: " << doubleValue << std::endl;
		return;
	}
}
