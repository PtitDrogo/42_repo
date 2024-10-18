#include "TFunctions.h"
#include <iostream>

#define MAGENTA "\033[1;35m"
#define END     "\033[0m"

int main()
{
    int int1 = 5;
    int int2 = 10;

    char char1 = 'A';
    char char2 = 'Z';

    std::cout << MAGENTA << "Time to use my Functions on an int !" << END << std::endl;
    std::cout << "1 is : " << int1 << ", 2 is : " << int2 << std::endl;
    std::cout << "max between var1 and var2 is : " << max(int1, int2) << std::endl;
    std::cout << "min between var1 and var2 is : " << min(int1, int2) << std::endl;
    std::cout << "lets swap values" << std::endl;
    swap(int1, int2);
    std::cout << "1 is : " << int1 << ", 2 is : " << int2 << std::endl;

    std::cout << std::endl << MAGENTA << "Time to use my Functions on a char !" << END << std::endl;
    std::cout << "1 is : " << char1 << ", 2 is : " << char2 << std::endl;
    std::cout << "max between var1 and var2 is : " << max(char1, char2) << std::endl;
    std::cout << "min between var1 and var2 is : " << min(char1, char2) << std::endl;
    std::cout << "lets swap values" << std::endl;
    swap(char1, char2);
    std::cout << "1 is : " << char1 << ", 2 is : " << char2 << std::endl;
    return 0;
}


