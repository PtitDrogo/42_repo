#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include "AForm.h"


class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    
    //methods
    void check_grade();

public:
    //Constructors
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat(const std::string& name);
    Bureaucrat(int grade);
    Bureaucrat(const std::string& name, int grade);
    //Destructors
    ~Bureaucrat();

    //Overloads
    Bureaucrat& operator=(const Bureaucrat& other);

    //Getters
    std::string getName() const;
    int getGrade() const;

    //methods
    void    incrementGrade();
    void    decrementGrade();
    void    signForm(AForm& form) const;

    //exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

    class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &fixed);
#endif