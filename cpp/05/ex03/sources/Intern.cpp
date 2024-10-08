#include "Intern.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>



Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other;}


Intern::~Intern() {}


//methods
    AForm *Intern::makePresidentialForm(std::string target) const {return (new PresidentialPardonForm(target));}
    AForm *Intern::makeRobotomyForm(std::string target) const {return (new PresidentialPardonForm(target));}
    AForm *Intern::makeShrubberyForm(std::string target) const {return (new PresidentialPardonForm(target));}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{ 
    try 
    {
        static const char *possibles_forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
        AForm* (Intern::*internFunctions[])(std::string) const = {&Intern::makePresidentialForm, &Intern::makeRobotomyForm, &Intern::makeShrubberyForm };
        for (int i = 0; i < 3; i++)
        {
            if (possibles_forms[i] == formName)
            {
                std::cout << possibles_forms[i] << " == " << formName << std::endl;
                std::cout << "Intern creates " << formName << std::endl;
                return (this->*internFunctions[i])(formTarget);
            }
        }
        throw InvalidFormName();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Intern couldnt make form " << formName << " because : " << e.what() << std::endl;
        return (NULL);
    } 
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        (void)other;
    }
    return (*this);
}
const char *Intern::InvalidFormName::what(void) const throw()  {return ("Invalid form name");};

std::ostream    &operator<<(std::ostream &out, Intern const &Intern)
{
    (void)Intern;
    out << "It's an Intern";
    return (out);
}