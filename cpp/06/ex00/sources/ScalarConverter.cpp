#include "ScalarConverter.h"
#include <iostream>
#include <cstdlib>


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
static e_type   identifyType(const std::string literal, const t_bools &bools);
static void     convertTime(const std::string literal, e_type type);
static bool     isPossiblyViableString(const std::string literal, t_bools &bools);
static void     printOutput(t_out vars);


//method
void ScalarConverter::convert(const std::string literal)
{
    std::string result;
    t_bools     bools = {};
    e_type        type;
    
    if (!isPossiblyViableString(literal, bools))
    {
        std::cout << "Cant convert this shit gotta reread subject to know what to write" << std::endl;
        return ;
    }
    type = identifyType(literal, bools);
    if (type == NONE)
    {
        std::cout << "Cant convert this shit gotta reread subject to know what to write" << std::endl;
        return ;
    }
    // std::cout << type << std::endl;
    convertTime(literal, type);

    return ;
}

//helper functions
static bool    isPossiblyViableString(const std::string literal, t_bools &bools)
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

//I want to convert the data, then I call a function that will print that data and print all 3 other data type 
//with a cast
static void convertTime(const std::string literal, e_type type)
{
    t_out vars;
    
    switch (type)
    {
    case INT:
        vars.i = std::atoi(literal.c_str());
        vars.c = static_cast<char>(vars.i);
        vars.f = static_cast<float>(vars.i);
        vars.d = static_cast<double>(vars.i);
        printOutput(vars);
        break;
    case CHAR:
        std::cout << "I WILL COME BACK TO THIS" << std::endl; //Extremely annoying because the input has to be taken has the decimal value and we print said decimal value char equivalent
        break;
    case FLOAT:
        vars.f = strtof(literal.c_str(), NULL);
        vars.i = static_cast<int>(vars.f);
        vars.c = static_cast<char>(vars.f);
        vars.d = static_cast<double>(vars.f);
        printOutput(vars);
        break;
    case DOUBLE:
        vars.d = strtod(literal.c_str(), NULL);
        vars.f = static_cast<float>(vars.d);
        vars.i = static_cast<int>(vars.d);
        vars.c = static_cast<char>(vars.d);
        printOutput(vars);
        break;
    default:
        break;
    }
    return ;
}

static void printOutput(t_out vars)
{
    std::cout << vars.i << std::endl;
    if (vars.i < 32 || vars.i > 128)
    {
        if (vars.i < 0 || vars.i == 128)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "Impossible" << std::endl;
    }
    else
        std::cout << vars.c << std::endl;
    // std::cout <<"DEBUG : "<< vars.f << std::endl;
    // std::cout <<"DEBUG : "<< static_cast<int>(vars.f) << std::endl;
    if (vars.f == static_cast<int>(vars.f)) //Check if there is even something after the dot.
    {
        std::cout << vars.f << ".0f" << std::endl;
        std::cout << vars.d << ".0" << std::endl;
    }
    else
    {
        std::cout << vars.f << "f" << std::endl;
        std::cout << vars.d << std::endl;
    }
}

static e_type identifyType(const std::string literal, const t_bools &bools)
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
    else if (bools.has_dot) {return DOUBLE;}
    return(NONE);

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