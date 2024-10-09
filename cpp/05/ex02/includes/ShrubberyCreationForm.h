#ifndef SCF_H
# define SCF_H

#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    //We dont want to call the default constructor;
    ShrubberyCreationForm();

public:
    //Constructors
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm(std::string target);
    
    //Destructors
    ~ShrubberyCreationForm();

    //methods 
    void execute(Bureaucrat const & executor) const;

    //new custom error
    class IOError : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

    //getters
    std::string getTarget() const;
    //Overloads
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
};

std::ostream    &operator<<(std::ostream &o, ShrubberyCreationForm const &fixed);


#endif