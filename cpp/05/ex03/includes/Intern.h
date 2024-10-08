#ifndef INTERN_H
# define INTERN_H

#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"

class Bureaucrat;

class Intern
{
private:
    AForm *makePresidentialForm(std::string target) const;
    AForm *makeRobotomyForm(std::string target) const;
    AForm *makeShrubberyForm(std::string target) const;

public:
    //Constructors
    Intern();
    Intern(const Intern& other);
    
    //Destructors
    ~Intern();

    //methods 
    AForm *makeForm(const std::string &formName, const std::string &formTarget) const;

    //exceptions
    class InvalidFormName : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
    
    //Overloads
    Intern& operator=(const Intern& other);
};

std::ostream    &operator<<(std::ostream &o, Intern const &fixed);
#endif