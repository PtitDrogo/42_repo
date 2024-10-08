#include "AForm.h"
#include <iostream>

AForm::AForm() : _name("noname"), _is_signed(false), _grade_sign(150), _grade_exec(150) {} //change this later perhaps
AForm::AForm(const AForm& other) : 
    _name(other.getName()),
    _is_signed(other.getSignedStatus()),
    _grade_sign(other.getGradeSign()), 
    _grade_exec(other.getGradeExec()) 
{check_grade();}

AForm::AForm(std::string name, int grade_sign, int grade_exec) :  
    _name(name),
    _is_signed(false),
    _grade_sign(grade_sign), 
    _grade_exec(grade_exec) 
{check_grade();}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_is_signed = other.getSignedStatus();
    }
    return (*this);
}

std::string AForm::getName() const { return _name; }
bool        AForm::getSignedStatus() const{ return _is_signed; }
int         AForm::getGradeExec() const { return _grade_exec; }
int         AForm::getGradeSign() const { return _grade_sign; }

void AForm::check_grade()
{
    if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
}
void AForm::beSigned(const Bureaucrat& Bureaucrat)
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

void AForm::checkRightsAndExec(Bureaucrat const & executor) const
{
    if (_grade_exec < executor.getGrade())
        throw GradeTooLowException();
    else if (_is_signed == false)
        throw FormNotSigned();
    else
        execute(executor);
}

const char *AForm::GradeTooHighException::what(void) const throw()  {return ("Grade too high");};
const char *AForm::FormNotSigned::what(void) const throw()          {return ("Form not signed");};
const char *AForm::GradeTooLowException::what(void) const throw()   {return ("Grade too low");};

std::ostream    &operator<<(std::ostream &out, AForm const &Form)
{
    out << std::boolalpha << "Form name : " << Form.getName() << ", Grade to execute : " << Form.getGradeExec() << ", Grade to sign : " << Form.getGradeSign();
    out << ", is_signed = " << Form.getSignedStatus();
    return (out);
}