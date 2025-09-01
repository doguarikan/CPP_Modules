#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define INT_MAX 2147483647.0
#define INT_MIN -2147483648.0

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip> 


class ScalarConverter {
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator=(const ScalarConverter &other);
	virtual ~ScalarConverter();

	public:
		static void convert(std::string const& literal);
};

#endif