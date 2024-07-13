#include "Fixed.h"

// Constructors
Fixed::Fixed() : _number(0)
{
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int basic_int)
{
    std::cout << "Int Constructor called" << std::endl;
    _number = basic_int << _precision;
}

Fixed::Fixed(const float basic_float)
{
    std::cout << "Float Constructor called" << std::endl;
    _number = roundf(basic_float * (1 << _precision));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// destructors
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// getters
int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (_number);
}

// setters
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _number = raw;
}
// methods
float Fixed::toFloat(void) const
{
    // std::cout << "toFloat member function called" << std::endl;
    return static_cast<float>(_number) / (1 << _precision);
}

float Fixed::toInt(void) const
{
    // std::cout << "toInt member function called" << std::endl;
    return (_number >> _precision);
}

// operators overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_number = other.getRawBits();
    }
    return (*this);
}
bool Fixed::operator<(const Fixed &other) const
{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->toFloat() <= other.toFloat());
}
bool Fixed::operator==(const Fixed &other) const
{
    return (this->toFloat() == other.toFloat());
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}
bool Fixed::operator+(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}
bool Fixed::operator-(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}
bool Fixed::operator*(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}
bool Fixed::operator/(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return (out);
}

