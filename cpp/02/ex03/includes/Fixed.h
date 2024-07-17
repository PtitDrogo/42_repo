#pragma once

//---Includes---//
#include <iostream>
#include <cmath>

//---Class---//
class Fixed
{
private:
    int _number;
    static const int _precision = 8;

public:
    
    //Getters
    int     getRawBits( void ) const;
    
    //Setters
    void    setRawBits( int const raw );
    
    //Methods
    float         toFloat( void ) const;
    float         toInt( void ) const;
    static Fixed  min(Fixed& a, Fixed& b);
    static Fixed  max(Fixed& a, Fixed& b);
    static Fixed  min(const Fixed& a, const Fixed& b);
    static Fixed  max(const Fixed& a, const Fixed& b);
    
    //Constructors
    Fixed();
    Fixed(const int basic_int);
    Fixed(const float basic_float);
    Fixed(const Fixed& other);
    
    //Overloads
    Fixed& operator=(const Fixed& other);
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    
    //Destructor
    ~Fixed();
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);