#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H
#include <iostream>

/*
- I have to read from the csv file;
- Most likely I put all the content of the csv file into my own set ?
- Set probably is the best since it would be weird for the same day to have two differet money value
- 


*/







class BitcoinExchange
{
private:
    int _x;
    int _y;
public:
    //Constructors
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange& other);
    BitcoinExchange(int a, int b);
    
    //Destructors
    ~BitcoinExchange();

    //Overloads
    BitcoinExchange& operator=(const BitcoinExchange& other);

    //Getters
    int getX() const;
    int getY() const;
};

std::ostream    &operator<<(std::ostream &o, BitcoinExchange const &fixed);
#endif