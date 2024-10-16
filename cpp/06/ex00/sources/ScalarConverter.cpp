#include "ScalarConverter.h"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <limits.h>
#include <limits>
#include <cmath> 

//Structs
enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NONE,
};

typedef struct s_char_bools {
    bool has_dot;
    bool has_f;
    bool has_plus;
    bool has_minus;
} t_bools;

typedef struct s_outputs {
    int    i;
    char   c;
    float  f;
    double d;
} t_out;

//prototypes
static bool     isForFunliterals(const std::string& literal);
static e_type   identifyType(const std::string &literal, const t_bools &bools);
static void     convertTime(const std::string &literal, e_type type);
static bool     isPossiblyViableString(const std::string& literal, t_bools &bools);
static void     printOutput(t_out vars);
static void     printChar(t_out vars);
static void     printInt(t_out vars);
static void     printFloat(t_out vars);
static void     printDouble(t_out vars);


//method
void ScalarConverter::convert(const std::string literal)
{
    std::string result;
    t_bools     bools = {};
    e_type        type;
    
    if (isForFunliterals(literal) == true)
        return ;
    if (!isPossiblyViableString(literal, bools))
    {
        std::cout << "Cannot convert string" << std::endl;
        return ;
    }
    type = identifyType(literal, bools);
    std::cout << type << std::endl;
    if (type == NONE)
    {
        std::cout << "Cannot convert string" << std::endl;
        return ;
    }
    convertTime(literal, type);

    return ;
}

//helper functions

static bool isForFunliterals(const std::string& literal)
{
    static const char *const funliterals[] = {"+inf", "-inf", "+inff", "-inff", "nan", NULL};
    int i = 0;
    
    for (i = 0; i < 5; i++)
    {
        if (literal == funliterals[i])
            break;
    }
    if (i == 5)
        return false;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "+inff" || literal == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (literal == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    return true;
}

static bool    isPossiblyViableString(const std::string& literal, t_bools &bools)
{
    int  strlen = literal.length();
    const std::string set = ".f-+";

    if (strlen == 1)
    {
        if (literal[0] < 0 || literal[0] > 127)
            return false;
        return true;
    }
    for (int i = 0; i < strlen; i++)
    {
        if (literal[i] == 'f')
        {
            if (bools.has_f)
                return false;
            bools.has_f = true;
        }
        else if (literal[i] == '.')
        {
            if (bools.has_dot)
                return false;
            bools.has_dot = true;
        }
        else if (literal[i] == '+')
        {
            if (bools.has_plus)
                return false;
            bools.has_plus = true;
        }
        else if (literal[i] == '-')
        {
            if (bools.has_minus)
                return false;
            bools.has_minus = true;
        }
        bool is_invalid_char = !std::isdigit((literal[i])) && set.find(literal[i]) == std::string::npos;
        if (is_invalid_char)
            return false;
    }
    return true;
}

static e_type identifyType(const std::string &literal, const t_bools &bools)
{
    if (literal.size() == 0)
        return NONE;
    if (bools.has_plus == true)
    {
        if (literal[0] != '+')
            return NONE;
    }
    if (bools.has_minus == true)
    {
        if (literal[0] != '-')
            return NONE;
    }
    if (literal.size() == 1) {return (CHAR);}
    else if (!bools.has_dot && !bools.has_f) {return INT;}
    else if (literal[literal.size() - 1] == 'f') {return FLOAT;}
    else if (bools.has_dot && !bools.has_f) {return DOUBLE;}
    return(NONE);
}

static void convertTime(const std::string &literal, e_type type)
{
    t_out vars;
    
    errno = 0;
    switch (type)
    {
    case INT:
    {
        long tmp = strtol(literal.c_str(), NULL, 10);
        if (tmp > INT_MAX || tmp < INT_MIN)
            errno = ERANGE; //Doing this because atoi doesnt have overflow detection;
        vars.i = std::atoi(literal.c_str());
        vars.c = static_cast<char>(vars.i);
        vars.f = static_cast<float>(vars.i);
        vars.d = static_cast<double>(vars.i);
        break;
    }
    case CHAR:
        vars.c = static_cast<char>(literal[0]);
        vars.f = static_cast<float>(vars.c);
        vars.d = static_cast<double>(vars.c);
        vars.i = static_cast<int>(vars.c);
        break;
    case FLOAT:
        vars.f = strtof(literal.c_str(), NULL);
        vars.i = static_cast<int>(vars.f);
        vars.c = static_cast<char>(vars.f);
        vars.d = static_cast<double>(vars.f);
        break;
    case DOUBLE:
        vars.d = strtod(literal.c_str(), NULL);
        vars.f = static_cast<float>(vars.d);
        vars.i = static_cast<int>(vars.d);
        vars.c = static_cast<char>(vars.d);
        break;
    default:
        break;
    }
    printOutput(vars);
    return ;
}

static void printOutput(t_out vars)
{
    if (errno == ERANGE)
    {
        //the idea being that even if i get an overflow from the main type, all other casting would be meaningless
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }
    printChar(vars);
    printInt(vars);
    printFloat(vars);
    printDouble(vars);
}

static void     printChar(t_out vars)
{
    std::cout << "char: ";
    if (vars.i < 32 || vars.i > 128)
    {
        if (vars.i < 0 || vars.i > 128)
            std::cout << "Impossible" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << vars.c << std::endl;
}
static void     printInt(t_out vars)
{
    if (vars.d > INT_MAX || vars.d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << vars.i << std::endl;
}
static void     printFloat(t_out vars)
{
    if (vars.d > std::numeric_limits<float>::max() || vars.d < std::numeric_limits<float>::min())
        std::cout << "float: impossible" << std::endl;
    else if (std::fmod(vars.f, 1.0) == 0.0) //Check if there is even something after the dot.
        std::cout << "float: " << vars.f << ".0f" << std::endl;
    else
        std::cout << "float: " << vars.f << "f" << std::endl;

}
static void     printDouble(t_out vars)
{
    if (std::fmod(vars.d, 1.0) == 0.0)
        std::cout << "double: " << vars.d << ".0" << std::endl;
    else
        std::cout << "double: " << vars.d << std::endl;
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


std::ostream    &operator<<(std::ostream &out, ScalarConverter const &fixed)
{
    (void)fixed;
    out << "How are you seeing this";
    return (out);
}