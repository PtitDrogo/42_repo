#pragma once

#include "Fixed.h"


class Point
{

private:
    const Fixed _x;
    const Fixed _y;


public:
    Point();
    ~Point();
    Point(const Point& other);
    Point(const Fixed a, const Fixed b);
    Point& operator=(const Point& other);

    //getters
    const Fixed& getX() const ;
    const Fixed& getY() const ;
    };

std::ostream    &operator<<(std::ostream &o, Point const &fixed);

bool bsp( Point const a, Point const b, Point const c, Point const point);  