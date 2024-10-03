#include "Bureaucrat.h"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("noname"), _grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : 
    _name(other.getName()), 
    _grade(other.getGrade()) 
{check_grade();}

Bureaucrat::Bureaucrat(const std::string& name) :  
    _name(name),
    _grade(150) 
{check_grade();}

Bureaucrat::Bureaucrat(int grade) :  
    _name("noname"),
    _grade(grade) 
{check_grade();}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :  
    _name(name),
    _grade(grade) 
{check_grade();}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        // this->_name = other.getName(); //Cant really copy a const name can we
        this->_grade = other.getGrade();
    }
    return (*this);
}


std::string Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void    Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}
void    Bureaucrat::incrementGrade()
{
    if (_grade + - 1 < 0)
        throw GradeTooHighException();
    _grade--;
}
void Bureaucrat::check_grade()
{
    if (_grade > 150)
        throw GradeTooHighException();
    if (_grade < 0)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade too low\n");
};

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade too high\n");
};

std::ostream    &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << " , bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}