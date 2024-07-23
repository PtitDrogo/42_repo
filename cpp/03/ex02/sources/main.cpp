#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include <iostream>

int main()
{
    FragTrap littleguy("mousey"); //name constructor
    std::cout << littleguy << " stats are, attack: " << littleguy.get_attack() << " hp: " << littleguy.get_hp() << " energy: " << littleguy.get_energy() << std::endl;
    littleguy.highFivesGuys();
    FragTrap copycat(littleguy);
    std::cout << copycat << " stats are, attack: " << copycat.get_attack() << " hp: " << copycat.get_hp() << " energy: " << copycat.get_energy() << std::endl;
    copycat.highFivesGuys();

    FragTrap new_guy("new guy");
    new_guy.attack("The wind at 6 am");
    new_guy.attack("The wind at 6 am");
    new_guy.attack("The wind at 6 am");
    new_guy.attack("The wind at 6 am");
    new_guy.attack("The wind at 6 am");
    new_guy.attack("The wind at 6 am");
    copycat = new_guy;
    std::cout << copycat << " stats are, attack: " << copycat.get_attack() << " hp: " << copycat.get_hp() << " energy: " << copycat.get_energy() << std::endl;
    copycat.highFivesGuys();
    return 0;
}