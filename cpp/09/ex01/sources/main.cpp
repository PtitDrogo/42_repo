#include "RPN.h"


int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    RPN PolishCalculator;

    try
    {
        PolishCalculator.calculateArgsPolishStyle(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "Error" << std::endl;
    }
    
    return 0;
}
