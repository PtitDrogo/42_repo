#ifndef Form_H
# define Form_H

#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
private:
    const       std::string _name;
    bool        _is_signed;
    const int   _grade_sign;
    const int   _grade_exec;

    //methods
    void check_grade();

public:
    //Constructors
    Form();
    Form(const Form& other);
    Form(std::string name, int grade_sign, int grade_exec);
    
    //Destructors
    ~Form();

    //methods
    void beSigned(const Bureaucrat& Bureaucrat);

    //Overloads
    Form& operator=(const Form& other);

    //Getters
    std::string getName() const;
    bool        getSignedStatus() const;
    int         getGradeSign() const;
    int         getGradeExec() const;

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

std::ostream    &operator<<(std::ostream &o, Form const &fixed);
#endif