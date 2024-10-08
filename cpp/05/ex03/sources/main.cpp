#include "Bureaucrat.h"
#include "AForm.h"
#include "Intern.h"
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
    Intern James;
    AForm *current_form;

    
    std::cout << MAGENTA << "Hello, my interns will now do some Forms !" << END << std::endl;
    
    //Failed Form
    std::cout << RED;
    current_form = James.makeForm("Epic Form Free Style", "My Dog");
    std::cout << END;
    if (current_form)
        std::cout << YELLOW << *current_form << END << std::endl;
    delete (current_form);
    
    //Robot form
    std::cout << GREEN;
    current_form = James.makeForm("RobotomyRequestForm", "My cat fan or robots");
    std::cout << END;
    if (current_form)
        std::cout << YELLOW << *current_form << END << std::endl;
    delete (current_form);
    
    //President Form
    std::cout << GREEN;
    current_form = James.makeForm("PresidentialPardonForm", "My cat fan or robots");
    std::cout << END;
    if (current_form)
        std::cout << YELLOW << *current_form << END << std::endl;
    delete (current_form);
    
    
    //shrubbery Form
    std::cout << GREEN;
    current_form = James.makeForm("ShrubberyCreationForm", "My cat fan or robots");
    std::cout << END;
    if (current_form)
        std::cout << YELLOW << *current_form << END << std::endl;
    delete (current_form);
    return 0;
}