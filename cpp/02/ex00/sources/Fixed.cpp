#include "Fixed.h"


Fixed::Fixed() : _number(0) 
{
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}


int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_number);
}

void     Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _number = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_number = other.getRawBits();
    }
    return (*this);
}