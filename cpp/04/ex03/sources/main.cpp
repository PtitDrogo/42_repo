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
        // IMateriaSource* src = new MateriaSource();
        // src->learnMateria(new Ice());
        // src->learnMateria(new Cure());
        // ICharacter* me = new Character("me");
        // AMateria* tmp;
        // tmp = src->createMateria("ice");
        // me->equip(tmp);
        // tmp = src->createMateria("cure");
        // me->equip(tmp);
        // ICharacter* bob = new Character("bob");
        // me->use(0, *bob);
        // me->use(1, *bob);
        // delete bob;
        // delete me;
        // delete src;
    }
    // Materia tests
    std::cout << "MY TESTS :" << std::endl;
    {
        // IMateriaSource *src = new MateriaSource();
        // Ice test_ice;
        // Cure test_cure;

        // Ice *Ice_clone  = test_ice.clone(); //this mallocs, its my job to free !
        // Cure *Cure_clone  = test_cure.clone(); // This mallocs, its my job to free !
        // //do use test here;
        // std::cout << *Ice_clone << std::endl;
        // std::cout << *Cure_clone << std::endl;

        // delete Ice_clone;
        // delete Cure_clone;
        // delete src;
    }
    // Sneaky Tests;
    {
        IMateriaSource *src = new MateriaSource();
        IMateriaSource *src2 = new MateriaSource();
        Ice *new_Ice = new Ice();

        src->learnMateria(new_Ice);
        src->learnMateria(new_Ice);
        src->learnMateria(new_Ice);
        src->learnMateria(new_Ice);
        src2->learnMateria(new_Ice);
        src2->learnMateria(new_Ice);
        src2->learnMateria(new_Ice);
        src2->learnMateria(new_Ice);
        src2->learnMateria(NULL);
        // See how I dont have to delete new_ice ? Very mindful, very
        delete src;
        delete src2;
    }
    return 0;
}
