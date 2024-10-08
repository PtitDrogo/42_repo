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
    
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file. No trees for you" << std::endl;
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

std::ostream    &operator<<(std::ostream &out, ShrubberyCreationForm const &ShrubberyCreationForm)
{
    out << static_cast<const AForm&>(ShrubberyCreationForm);
    out << ", Target is " << ShrubberyCreationForm.getTarget();
    return (out);
}