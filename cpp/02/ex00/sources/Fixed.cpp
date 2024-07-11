#include "Fixed.h"


Fixed::Fixed() : _number(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other)
{
    this->_number = other._number;
}


int     Fixed::getRawBits( void ) const
{
    return (_number);
}

void     Fixed::setRawBits(int const raw)
{
    _number = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        
    }

}