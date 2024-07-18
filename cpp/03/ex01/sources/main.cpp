#include "ClapTrap.h"
#include <iostream>

int main()
{
    ClapTrap A("Gandin");

    std::cout << A << " is here" << std::endl;

    A.attack("Innocent Bystander");
    std::cout << "Security didnt like this and attacks Gandin" << std::endl;
    A.takeDamage(4);
    std::cout << "Gandin has to do something !" << std::endl;
    A.beRepaired(3);
    A.beRepaired(10000);
    std::cout << "God Strikes down Gandin" << std::endl;
    A.takeDamage(10000);
    std::cout << "God Strikes down Gandin Again to make sure" << std::endl;
    A.takeDamage(1);

    ClapTrap B(A);
    ClapTrap C = A;
    std::cout << "Two ghosts Appeared ! God will smite them both" << std::endl;

    B.takeDamage(1);
    C.takeDamage(1);

    ClapTrap Kungfu("Bruce lee");

    std::cout << "Thousand fists of rage" << std::endl;
    for (int i = 0; i < 15; i++)
        Kungfu.attack("God");


    return 0;
}