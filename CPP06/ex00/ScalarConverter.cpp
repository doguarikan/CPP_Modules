#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter  &other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isLiteralChar(const std::string& s) { return s.length() == 1 && !std::isdigit(s[0]); }

static bool isLiteralFloat(const std::string& s) { return s == "nanf" || s == "+inff" || s == "-inff"; }

static bool isLiteralDouble(const std::string& s) { return s == "nan" || s == "+inf" || s == "-inf"; }

void ScalarConverter::convert(const std::string& literal) {
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    std::cout << std::fixed << std::setprecision(1);

    if (isLiteralChar(literal)) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else if (isLiteralFloat(literal)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return ;
    } else if (isLiteralDouble(literal)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return ;
    } else {
        char* end;
        d = std::strtod(literal.c_str(), &end);

        if (*end != '\0' && *end != 'f') {
            std::cout << "Error: invalid input" << std::endl;
            return ;
        }
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
    }
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
