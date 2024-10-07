#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define END     "\033[0m"

int main()
{
    Form default_form;
    Form doomform("The form of Doom", 20, 20);
    Form copy_of_custom(doomform);
    Form overload_form;
    Bureaucrat macron("Macron", 1);
    Bureaucrat random("Random Fonctionnaire", 125);

    std::cout << MAGENTA "Welcome to my main"  END << std::endl << std::endl;
    std::cout << BLUE "Default constructor : " END << WHITE << default_form << END << std::endl;
    std::cout << BLUE "Custom constructor : " END << WHITE << doomform << END << std::endl;
    std::cout << BLUE "Copy constructor : " END << WHITE << copy_of_custom << END << std::endl;
    overload_form = doomform;
    std::cout << BLUE "overload = test, is it like custom form : " END << WHITE << overload_form << END << YELLOW " (We didnt copy the grades since its const !)" END << std::endl;

    std::cout << MAGENTA "Time to try to create impossible forms"  END << std::endl << std::endl;
    try
    {
        Form test("Its over 9000 form", 0,9000);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Look mom I caught this error : " << e.what()  << END << std::endl;
    }
    try
    {
        Form test("Its under 9000 form", -9000, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Look mom I caught this error : " << e.what()  << END << std::endl;
    }



    std::cout << MAGENTA "Time to sign the form of Doom thats lvl 20, Macron can do it, but can the random fonctionnaire ?"  END << std::endl << std::endl;

    std::cout << BLUE;
    macron.signForm(doomform);
    std::cout << END;
    std::cerr << RED;
    random.signForm(doomform);
    std::cerr << END;

    return 0;
}
