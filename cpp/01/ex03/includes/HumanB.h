#ifndef HUMANB_H
#define HUMANB_H

#include "main.h"

class HumanB
{
private:
    Weapon *_weapon;
    std::string _name;

public:
    void attack();
    void setWeapon(Weapon &Weapon);
    HumanB(std::string name);
    ~HumanB();
};

#endif