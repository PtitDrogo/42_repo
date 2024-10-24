#include "BitcoinExchange.h"


int main(int argc, char const *argv[])
{
    (void)argv;
    std::ifstream ifs;

    // if (argc != 2 || ifs.is_open() == false)
    // {
    //     std::cerr << "Error: could not open file." << std::endl;
    //     return (1);
    // }
    // ifs.open("data.csv");
    // if (ifs.is_open() == false)
    // {
    //     std::cerr << "Error: could not open database file." << std::endl;
    //     return (1);
    // }
    // ifs.close();

    BitcoinExchange hello;

    hello.exchangeBitcoin(argv[1]);
    return 0;
}




