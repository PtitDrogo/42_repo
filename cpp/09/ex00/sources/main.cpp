#include "BitcoinExchange.h"


int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    
    try 
    {
        BitcoinExchange hello;
        BitcoinExchange hi;
        hi = hello;
        BitcoinExchange hi2(hello);

        hello.exchangeBitcoin(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}




