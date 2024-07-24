#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include "DiamondTrap.h"
#include <iostream>

int main()
{
    {
        DiamondTrap steve; //default constructor
        steve.attack("the universe all at once");
        std::cout << steve << " stats are, attack: " << steve.get_attack() << " hp: " << steve.get_hp() << " energy: " << steve.get_energy() << std::endl;
        std::cout << std::endl;
    }
        std::cout << std::endl;
    {
        DiamondTrap steve("real steve"); //name constructor
        std::cout << std::endl;
        DiamondTrap new_guy(steve); //copy constructor
        std::cout << std::endl;
        DiamondTrap newest_guy = steve;
        std::cout << std::endl;
        steve.whoAmI();
        new_guy.whoAmI();
        newest_guy.whoAmI();
        std::cout << std::endl;
    }

    return 0;
}