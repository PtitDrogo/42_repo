#ifndef WEAPON_H
# define WEAPON_H

#include "main.h"

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string type);
    Weapon();
    ~Weapon();
    const std::string& getType() const;
    void setType(const std::string type);
};

#endif