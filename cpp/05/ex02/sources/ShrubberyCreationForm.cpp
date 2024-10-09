#include "ShrubberyCreationForm.h"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other.getTarget()) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}


ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {return _target;}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    char trees[][32] = {
    "   /\\        /\\        /\\   ",
    "  /  \\      /  \\      /  \\  ",
    " /    \\    /    \\    /    \\ ",
    "/______\\  /______\\  /______\\",
    "   ||         ||          ||   ",
    "   ||         ||          ||   "
};
    std::ofstream outFile((_target + "_shrubbery").c_str());
    
    try 
    {
        if (!outFile.is_open()) 
            throw IOError();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error execute shrubbery form because : "<< e.what() << std::endl;
        return ;
    }
    
    for (int i = 0; i < 6; ++i) {
        outFile << trees[i] << std::endl;
    }
    outFile.close();
    std::cout << executor.getName() << " executed form " << (*this).getName() << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other.getTarget();
    }
    return (*this);
}
//error
const char *ShrubberyCreationForm::IOError::what(void) const throw()  {return ("Error opening the target file");};

std::ostream    &operator<<(std::ostream &out, ShrubberyCreationForm const &ShrubberyCreationForm)
{
    out << static_cast<const AForm&>(ShrubberyCreationForm);
    out << ", Target is " << ShrubberyCreationForm.getTarget();
    return (out);
}