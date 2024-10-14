#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <iostream>

class ScalarConverter
{
private:
    //Constructors
    ScalarConverter();
    ScalarConverter(ScalarConverter& other);
    
    //Destructors
    ~ScalarConverter();
public:
    //Overloads
    static void convert(const std::string literal);
    ScalarConverter& operator=(const ScalarConverter& other);
};

std::ostream    &operator<<(std::ostream &o, ScalarConverter const &fixed);
#endif