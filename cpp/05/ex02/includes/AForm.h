#ifndef AForm_H
# define AForm_H

#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm
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
    AForm();
    AForm(const AForm& other);
    AForm(std::string name, int grade_sign, int grade_exec);
    
    //Destructors
    ~AForm();

    //methods
    void beSigned(const Bureaucrat& Bureaucrat);

    //Overloads
    AForm& operator=(const AForm& other);

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

std::ostream    &operator<<(std::ostream &o, AForm const &fixed);
#endif