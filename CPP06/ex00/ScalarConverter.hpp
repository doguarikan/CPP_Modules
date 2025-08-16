#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define INT_MAX 2147483647.0
#define INT_MIN -2147483648.0

#include <cstdlib>
#include <iostream>
#include <string>


class ScalarConverter
{
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	virtual ~ScalarConverter(void);
	ScalarConverter& operator=(const ScalarConverter &copy);

	public:
		static void convert(std::string const& value);
};

#endif