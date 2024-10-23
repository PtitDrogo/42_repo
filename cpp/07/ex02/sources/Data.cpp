#include "Data.h"

Data::Data() : food(15), wood(0), stone(0), gold(0) {}

Data::Data(const Data& other) : 
food(other.getFood()),
wood(other.getWood()),
stone(other.getStone()),
gold(other.getGold())
{}

Data::~Data() {}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        food = other.getFood();
        wood = other.getWood();
        stone = other.getStone();
        gold = other.getGold();
    }
    return (*this);
}

size_t Data::getFood() const {return food;}
size_t Data::getWood() const {return wood;}
size_t Data::getStone() const {return stone;}
size_t Data::getGold() const {return gold;}

std::ostream& operator<<(std::ostream& o, const Data& toprint)
{
    o << "Data is : Food - " << toprint.getFood() << ", Wood - " << toprint.getWood() << ", Stone - "  << toprint.getStone() << ", Gold - " << toprint.getGold();
    return (o);
}

