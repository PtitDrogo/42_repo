#include "Point.h"


Point::Point() : _x(0), _y(0) {}

Point::~Point() {}

Point::Point(const Fixed a, const Fixed b) : _x(a), _y(b) {}

Point &Point::operator=(const Point &other)
{
    (void)other; // in search of a better way
    return (*this);
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

const Fixed& Point::getX() const { return _x; }
const Fixed& Point::getY() const { return _y; }


std::ostream    &operator<<(std::ostream &out, Point const &fixed)
{
    out << "(" << fixed.getX() << "," << fixed.getY() << ")";
    return (out);
}


