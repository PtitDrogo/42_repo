#include "ClapTrap.h"
#include "ScavTrap.h"
#include <iostream>

int main()
{
    std::cout.setf(std::ios::boolalpha);
    {
        ScavTrap nameless; //Default constructor
        std::cout << nameless << " stats, HP : " << nameless.get_hp() << " Attack : " << nameless.get_attack() << " energy : "<< nameless.get_energy() << std::endl;
    }
    std::cout << std::endl;
    {
        ClapTrap A("Gandin"); //name constructor
        std::cout << A << " stats, HP : " << A.get_hp() << " Attack : " << A.get_attack() << " energy : "<< A.get_energy() << std::endl;
        ScavTrap Scavvie("Scavvie");
        ScavTrap copycat(Scavvie); //copy constructor
        std::cout << copycat << " stats, HP : " << copycat.get_hp() << " Attack : " << copycat.get_attack() << " energy : "<< copycat.get_energy() << std::endl;
        copycat.attack("A Wall, for some reason");
        std::cout << copycat.get_energy() << " energy left for " << copycat << std::endl;
    }
    std::cout << std::endl;
    {
        ScavTrap OG_Steve("Steve");
        ClapTrap Steve(OG_Steve); //Test for fun, Slicing here ! But it works as much as it can;
        std::cout << OG_Steve << " stats, HP : " << OG_Steve.get_hp() << " Attack : " << OG_Steve.get_attack() << " energy : "<< OG_Steve.get_energy() << std::endl;
        std::cout << Steve << " stats, HP : " << Steve.get_hp() << " Attack : " << Steve.get_attack() << " energy : "<< Steve.get_energy() << std::endl;
        OG_Steve.guardGate();
        std::cout << OG_Steve << " is guarding the gate = " << OG_Steve.get_status() << std::endl;
        OG_Steve.stopGuard();
        std::cout << OG_Steve << " is guarding the gate = " << OG_Steve.get_status() << std::endl; 
    }
    std::cout << std::endl;
    {
        ScavTrap OG_Steve("Steve");
        ScavTrap new_steve = OG_Steve;
        std::cout << OG_Steve << " stats, HP : " << OG_Steve.get_hp() << " Attack : " << OG_Steve.get_attack() << " energy : "<< OG_Steve.get_energy() << std::endl;
        std::cout << "new_steve stats, HP : " << new_steve.get_hp() << " Attack : " << new_steve.get_attack() << " energy : "<< new_steve.get_energy() << std::endl;
    }
        std::cout << std::endl;
    return 0;
}