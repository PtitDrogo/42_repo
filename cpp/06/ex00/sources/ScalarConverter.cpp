#include "ScalarConverter.h"
#include <iostream>
#include <sstream> 

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& other) { (void)other;}
ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
    {
        //do nothing
    }
    return (*this);
}

void ScalarConverter::convert(const std::string literal)
{
    std::stringstream ss;
    std::string result;

    int     i;
    float   f;
    double  d;
    char    c;

    ss << literal;
    
    ss >> c;
    if (ss.fail() || literal.length() != 1) {
        std::cerr << "FAUX" << std::endl;
    } else {
        std::cout << "Converted number: " << c << std::endl;
    }
    //char / int / float / double
    //We will now put the stuff in ss and try to extract data of each type from it I guess.
    std::cout << result << std::endl;
    return ;
}

std::ostream    &operator<<(std::ostream &out, ScalarConverter const &fixed)
{
    (void)fixed;
    out << "How are you seeing this";
    return (out);
}