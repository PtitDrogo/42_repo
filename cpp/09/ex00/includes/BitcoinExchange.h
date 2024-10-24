#ifndef BITCOIN_EXCHANGE_H
# define  BITCOIN_EXCHANGE_H

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, double> database;

    //methods
    bool    isInputFileValid(const char *filename);
    void    fillMap();

public:
    //Constructors
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange& other);
    
    //Destructors
    ~BitcoinExchange();

    //Overloads
    BitcoinExchange& operator=(const BitcoinExchange& other);

    //Getters
};

std::ostream    &operator<<(std::ostream &o, BitcoinExchange const &fixed);

#endif