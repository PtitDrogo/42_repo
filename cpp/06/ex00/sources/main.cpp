#include "ScalarConverter.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string result;
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    // ScalarConverter::convert("Y");
    // ScalarConverter::convert("+");
    // ScalarConverter::convert("-");
    // ScalarConverter::convert("2");
    // ScalarConverter::convert("-1");
    // ScalarConverter::convert(".");
    // ScalarConverter::convert("*");
    // ScalarConverter::convert("awdawdawdadawdwd");
    // ScalarConverter::convert("++123123213");
    // ScalarConverter::convert("-+123123123");
    // ScalarConverter::convert("-213213+");
    // ScalarConverter::convert("+42");
    // ScalarConverter::convert("42f");
    // ScalarConverter::convert("4200.5f");
    // ScalarConverter::convert("42.");
    // ScalarConverter::convert("+");
    // ScalarConverter::convert("-");
    ScalarConverter::convert(argv[1]);
    ScalarConverter::convert("111111111111111111111111111111111111111.2f"); //MAX FLOAT
    ScalarConverter::convert("123112312312.31232311111f");
    return 0;
}

