#include "Fixed.h"

// Constructors
Fixed::Fixed() : _number(0)
{
    // std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int basic_int)
{
    // // std::cout << "Int Constructor called" << std::endl;
    _number = basic_int << _precision;
}

Fixed::Fixed(const float basic_float)
{
    // std::cout << "Float Constructor called" << std::endl;
    _number = roundf(basic_float * (1 << _precision));
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// destructors
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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
    // std::cout << "setRawBits member function called" << std::endl;
    _number = raw;
}
// methods
float Fixed::toFloat(void) const
{
    // std::cout << "toFloat member function called" << std::endl;
    return static_cast<float>(_number) / (1 << _precision);
}

float Fixed::toInt() const
{
    // std::cout << "toInt member function called" << std::endl;
    return (_number >> _precision);
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}



// operators overload
Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_number = other.getRawBits();
    }
    return (*this);
}
bool Fixed::operator<(const Fixed &other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (this->getRawBits() != other.getRawBits());
}
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed tmp;

    tmp._number = this->getRawBits() + other.getRawBits();
    
    return (tmp);
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed tmp;

    tmp._number = this->getRawBits() - other.getRawBits();
    
    return (tmp);
}
Fixed Fixed::operator*(const Fixed &other) const
{
    long int x = _number;
    x *= other._number;
    x >>= _precision;
    Fixed result;
    result.setRawBits(x);
    return result;
   
//    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const
{
    long int x = _number << _precision;
    x /= other._number;
    Fixed result;
    result.setRawBits(x);
    return result;
    // return Fixed(this->toFloat() / other.toFloat());
}
Fixed Fixed::operator++(int)
{
    Fixed prev(*this);
    
    ++*this;
    return (prev);
}

Fixed Fixed::operator--(int)
{
    Fixed prev(*this);
    
    --*this;
    return (prev);
}

Fixed &Fixed::operator++()
{
    ++(this->_number);
    return (*this);
}

Fixed &Fixed::operator--()
{
    --(this->_number);
    return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return (out);
}
