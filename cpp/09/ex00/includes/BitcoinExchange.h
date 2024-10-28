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
    std::map<std::string, double> _database;

    //methods
    void    fillMap();
    void    parseLine(const std::string& line) const;
    void    sanitizeLine(const std::string& line);
    void    getDateAndCompare(const std::string& line, double number_bitcoins) const;
    bool    isValidNumberBitcoinsValue(const std::string& line, double &number_bitcoins) const;

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

#endif
