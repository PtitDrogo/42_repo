#include "Fixed.h"
#include "Point.h"


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    std::cout << a << std::endl; 
    std::cout << b << std::endl; 
    std::cout << c << std::endl; 
    std::cout << point << std::endl;


    return (true);
}

double sideOfLine(const Point& p1, const Point& p2, const Point& p) 
{
    
    return ((p2.getX()) - (p1.getX())) * ((p.getY()) - (p1.getY())) - ((p2.getY()) - (p1.getY())) * ((p.getX()) - (p1.getX()));
}
