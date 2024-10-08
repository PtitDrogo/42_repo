#include "Form.h"
#include <iostream>

Form::Form() : _name("noname"), _is_signed(false), _grade_sign(150), _grade_exec(150) {} //change this later perhaps
Form::Form(const Form& other) : 
    _name(other.getName()),
    _is_signed(other.getSignedStatus()),
    _grade_sign(other.getGradeSign()), 
    _grade_exec(other.getGradeExec()) 
{check_grade();}

Form::Form(std::string name, int grade_sign, int grade_exec) :  
    _name(name),
    _is_signed(false),
    _grade_sign(grade_sign), 
    _grade_exec(grade_exec) 
{check_grade();}

Form::~Form() {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_is_signed = other.getSignedStatus();
    }
    return (*this);
}

std::string Form::getName() const { return _name; }
bool        Form::getSignedStatus() const{ return _is_signed; }
int         Form::getGradeExec() const { return _grade_exec; }
int         Form::getGradeSign() const { return _grade_sign; }

void Form::check_grade()
{
    if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
}
void Form::beSigned(const Bureaucrat& Bureaucrat)
{
    if (Bureaucrat.getGrade() > _grade_sign) //having a bigger grade means its not good enough    
    {    
        throw GradeTooLowException();
    }
    else
    {
        _is_signed = true;
    }
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
};

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
};

std::ostream    &operator<<(std::ostream &out, Form const &Form)
{
    out << std::boolalpha << "Form name : " << Form.getName() << ", Grade to execute : " << Form.getGradeExec() << ", Grade to sign : " << Form.getGradeSign();
    out << ", is_signed = " << Form.getSignedStatus();
    return (out);
}