#include <string>
#include <iostream>

int main(void)
{
    std::string var = "HI THIS IS BRAIN";
    std::string *stringPTR = &var;
    std::string& stringREF = var;

    //PRINTING MEMORY ADDRESSES
    std::cout << "Memory address of var: " << &var << std::endl;
    std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
    
    //PRINTING VALUES
    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Value pointed at by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl;

    return 0;
}
