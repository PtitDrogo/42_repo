#include "ScalarConverter.h"
#include <iostream>
#include <sstream> 

enum type {
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
};


static type identifyType(const std::string literal)
{
    //42.0f is a float;
    //42.0 is a double;
    //42 is an int

    //the only non numbers characters that are possible are |+|-|f|.|
    //all of these can have one + or one - at the start, not more;
    //must always be at the end for it to be considered a float;
    //there must only be one .
    
    //LETS CHECK IF THE LAST CHARACTER IS f, if not, it cant be a float;
    // 

    //First lets scan if there is any non wanted character;
    for (int i = 0; i < literal.size(); i++)
    {
        

    }


    if (literal.size() == 1 && literal[0] >= 32 && literal[0] <= 126)
    {
        return (CHAR); //this will make 0 to 9 count as char, such is life gotta pick one;        
    }
    else if (literal[literal.size() - 1] == 'f')
    {
        //Do check for numbers

    }
    else if ()
    {

    }
    else if ()
    {

    }
    else
    {
        std::cout << "wtf" << std::endl;
    }


}

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

    std::cout << result << std::endl;
    return ;
}

std::ostream    &operator<<(std::ostream &out, ScalarConverter const &fixed)
{
    (void)fixed;
    out << "How are you seeing this";
    return (out);
}