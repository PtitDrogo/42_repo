#include "AMateria.h"
#include "Cure.h"
#include "Ice.h"
#include "Character.h"
#include "ICharacter.h"
#include "MateriaSource.h"
#include "IMateriaSource.h"

int main()
{
    std::cout << std::endl << "Subject TEST :" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    
    std::cout << std::endl << "MY TESTS :" << std::endl;
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        Character* bob = new Character("Bob");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        bob->equip(tmp);
        tmp = src->createMateria("cure");
        bob->equip(tmp);
        std::cout << *bob << std::endl;
        bob->unequip(1);
        std::cout << *bob << std::endl;
        bob->equip(tmp);
        std::cout << *bob << std::endl;
        bob->use(0, *bob);
        bob->use(1, *bob);
        bob->use(2, *bob);
        bob->use(3, *bob);
        bob->unequip(1);
        std::cout << *bob << std::endl;

        Character *new_bob = new Character(*bob);
        std::cout << *new_bob << std::endl;
        

        delete new_bob;
        delete bob;
        delete src;
    }
    std::cout << std::endl << "TESTS : this will break other Githubs" << std::endl;
    {
        //Two materias Sources Sharing pointers;
        {
            IMateriaSource *src = new MateriaSource();
            IMateriaSource *src2 = new MateriaSource();
            Ice *new_Ice = new Ice();

            src->learnMateria(new_Ice);
            src->learnMateria(new_Ice);
            src->learnMateria(new Ice());
            src->learnMateria(new Cure());
            src2->learnMateria(new_Ice);
            src2->learnMateria(new_Ice);
            src2->learnMateria(new Ice());
            src2->learnMateria(new Cure());
            src2->learnMateria(NULL);
            
        //Two characters unequipping and equipping multiple times the same shared equipement;
            Character* bob = new Character("Bob");
            Character* steve = new Character("Steve");

            AMateria* tmp = src->createMateria("ice");
            AMateria* tmp2 = src2->createMateria("cure");
            
            bob->unequip(0);
            bob->unequip(15);
            
            bob->equip(tmp);
            steve->equip(tmp); // Bob has that !
            steve->equip(tmp2);
            bob->equip(tmp); //Steve has that !
            std::cout << *bob << std::endl;
            std::cout << *steve << std::endl;

            steve->unequip(0);
            steve->unequip(0);
            bob->use(0, *steve);
            steve->use(0, *bob);

            delete bob;
            delete steve;
            delete src;
            delete src2;
        }
    }
    return 0;
}
