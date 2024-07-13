#ifndef FIXED_H
# define FIXED_H

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
    float   toFloat( void ) const;
    float   toInt( void ) const;
    
    //Constructors
    Fixed();
    Fixed(const int basic_int);
    Fixed(const float basic_float);
    Fixed(const Fixed& other);
    
    //Overloads
    Fixed& operator=(const Fixed& other);
    
    //Destructor
    ~Fixed();
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif