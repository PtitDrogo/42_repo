#ifndef BITCOIN_EXCHANGE_H
# define  BITCOIN_EXCHANGE_H

#include <iostream>
class BitcoinExchange
{
private:

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