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

int main()
{
    Bureaucrat macron("Macron", 20);   
    PresidentialPardonForm bigform("Jean");
    PresidentialPardonForm bigform2("The world");
    std::cout << bigform << std::endl << bigform2 << std::endl;
    bigform = bigform2;
    std::cout << bigform << std::endl << bigform2 << std::endl;
    macron.signForm(bigform);
    bigform.execute(macron);

    return 0;
}