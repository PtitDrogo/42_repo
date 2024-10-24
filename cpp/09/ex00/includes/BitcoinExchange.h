#ifndef BITCOIN_EXCHANGE_H
# define  BITCOIN_EXCHANGE_H

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cerrno>
#include <limits.h>

class BitcoinExchange
{
private:
    std::map<std::string, double> database;

    //methods
    void    fillMap();
    bool    isInputTextLineValid(const std::string& line) const;

public:

    //methods
    void    exchangeBitcoin(const char *filename) const;
    
    
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