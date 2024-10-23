#include "BitcoinExchange.h"
#include <iostream>

BitcoinExchange::BitcoinExchange() : _x(0), _y(0) {}
BitcoinExchange::BitcoinExchange(int a, int b) : 
    _x(a), 
    _y(b) {}
BitcoinExchange::BitcoinExchange(BitcoinExchange& other) : 
    _x(other.getX()), 
    _y(other.getY()) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->_x = getX();
        this->_y = getY();
    }
    return (*this);
}


int BitcoinExchange::getX() const { return _x; }
int BitcoinExchange::getY() const { return _y; }

std::ostream    &operator<<(std::ostream &out, BitcoinExchange const &fixed)
{
    out << "X is " << fixed.getX() << " Y is " << fixed.getY();
    return (out);
}