#include "main.h"

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::ignore( void )
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
void Harl::complain( std::string level )
{
    void    (Harl::*functions[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::ignore};
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
	{
		if (level == complains[i])
		{
			switch (i)
			{
				case 0:
					(this->*functions[0])();
					(this->*functions[1])();
					(this->*functions[2])();
					(this->*functions[3])();
					break;
				case 1:
					(this->*functions[1])();
					(this->*functions[2])();
					(this->*functions[3])();
					break;
				case 2:
					(this->*functions[2])();
					(this->*functions[3])();
					break;
				case 3:
					(this->*functions[3])();
					break;
				default:
					break;
			}
			return;
		}
	}
    (this->*functions[4])();
}

Harl::Harl()
{
}

Harl::~Harl()
{
}