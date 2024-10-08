#include "Bureaucrat.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include <iostream>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define END     "\033[0m"

#define PRINTERR(x) std::cout << RED; x; std::cout << END
#define PRINTGOOD(x) std::cout << GREEN; x; std::cout << END
#define PRINTNEUTRAL(x) std::cout << YELLOW; x; std::cout << END

int main()
{
    Bureaucrat macron("Macron", 20); 
    Bureaucrat god("God", 1);
    Bureaucrat steve("Steve", 60);  
    PresidentialPardonForm bigform("Jean");

    //presidential pardon form
    std::cout << YELLOW << bigform << END << std::endl;
    std::cout << MAGENTA << "Macron wants to sign a Pardon form, but he forgot to sign it !" << END << std::endl;
    PRINTERR(macron.executeForm(bigform));
    PRINTGOOD(macron.signForm(bigform));
    PRINTERR(macron.executeForm(bigform));
    std::cout << MAGENTA << "Macron cant execute the form, gotta call God" << END << std::endl;
    PRINTGOOD(god.executeForm(bigform));
    std::cout << std::endl << std::endl;

    //robotomized form
    RobotomyRequestForm roboform("Cyborg Wanna be");
    std::cout << YELLOW << roboform << END << std::endl;
    std::cout << MAGENTA << "Steve turn to forget to sign!" << END << std::endl;
    PRINTERR(steve.executeForm(roboform));
    PRINTGOOD(steve.signForm(roboform));
    PRINTERR(steve.executeForm(roboform));
    std::cout << MAGENTA << "Steve cant execute the form, gotta call Macron" << END << std::endl;
    PRINTNEUTRAL(macron.executeForm(roboform));
    std::cout << std::endl << std::endl;

    //Shrubbery Form
    ShrubberyCreationForm trees("birds");
    std::cout << YELLOW << trees << END << std::endl;
    std::cout << MAGENTA << "Steve will forget to sign! again !" << END << std::endl;
    PRINTERR(steve.executeForm(trees));
    PRINTGOOD(steve.signForm(trees));
    PRINTGOOD(steve.executeForm(trees));
    std::cout << MAGENTA << "at least Steve has a green thumb" << END << std::endl;



    return 0;
}