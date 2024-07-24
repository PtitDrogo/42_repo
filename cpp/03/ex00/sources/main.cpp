#include "ClapTrap.h"
#include <iostream>

int main()
{
    {
        ClapTrap noname; //default constructor

        std::cout << noname << " is here, and quickly forgotten" << std::endl;
    }
    std::cout << std::endl;
    ClapTrap A("Gandin"); // name constructor

    std::cout << A << " is here" << std::endl;

    A.attack("Innocent Bystander");
    std::cout << "Security didnt like this and attacks Gandin" << std::endl;
    A.takeDamage(4);
    std::cout << "Gandin has to do something !" << std::endl;
    A.beRepaired(3);
    A.beRepaired(10000);
    A.beRepaired(4294967295); //cheeky max value
    std::cout << "Gandin hp after all this is "<< A.get_hp() << std::endl;
    std::cout << "God Strikes down Gandin" << std::endl;
    A.takeDamage(-1); //cheeky max value
    std::cout << "God Strikes down Gandin Again to make sure" << std::endl;
    A.takeDamage(1);
    std::cout << "Gandin hp after all this is "<< A.get_hp() << std::endl;

    ClapTrap B(A); //copy constructor
    ClapTrap C = A; //assignement overload
    std::cout << "Two ghosts Appeared ! God will smite them both" << std::endl;

    B.takeDamage(1);
    C.takeDamage(1);

    ClapTrap Kungfu("Bruce lee");

    std::cout << "Thousand fists of rage" << std::endl;
    for (int i = 0; i < 15; i++)
        Kungfu.attack("God");
    Kungfu.beRepaired(10);

    return 0;
}