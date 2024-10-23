#ifndef DATA_H
# define DATA_H

#include <iostream>
#include <stdint.h>

class Data
{
private:
    size_t food;
    size_t wood;
    size_t stone;
    size_t gold;
public:
    Data();
    Data(const Data& other);
    ~Data();

Data& operator=(const Data& other);

size_t getFood() const;
size_t getWood() const;
size_t getStone() const;
size_t getGold() const;

};

std::ostream& operator<<(std::ostream& o, const Data& toprint);

#endif