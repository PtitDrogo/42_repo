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

#endif