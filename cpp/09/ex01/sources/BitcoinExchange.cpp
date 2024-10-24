#include "BitcoinExchange.h"
#include <iostream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange& other) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {

    }
    return (*this);
}


std::ostream    &operator<<(std::ostream &out, BitcoinExchange const &fixed)
{
    out << "btc class whoah !";
    return (out);
}