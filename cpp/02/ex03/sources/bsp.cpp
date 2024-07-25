#include "Fixed.h"
#include "Point.h"

Fixed sideOfLine(const Point& p1, const Point& p2, const Point& p);


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    std::cout << "New Triangle a b c and point:" << std::endl;
    std::cout << a << std::endl; 
    std::cout << b << std::endl;
    std::cout << c << std::endl; 
    std::cout << point << std::endl;

    Fixed d1 = sideOfLine(a, b, point);
    std::cout << "result is : " << d1 << std::endl; 
    Fixed d2 = sideOfLine(b, c, point);
    std::cout << "result is : " << d2 << std::endl;
    Fixed d3 = sideOfLine(c, a, point);
    std::cout << "result is : " << d3 << std::endl;

    bool is_all_positive = (d1 < 0) && (d2 < 0) && (d3 < 0);
    bool is_all_negative = (d1 > 0) && (d2 > 0) && (d3 > 0);

    return (is_all_positive || is_all_negative);
}

Fixed sideOfLine(const Point& p1, const Point& p2, const Point& p) 
{   
    // std::cout << "(" << p2.getX() << " - " << p1.getX() << ")" << " * " << "(" << p.getY() << " - " << p1.getY() << ")";
    // std::cout << " - " ;d
    // std::cout << "(" << p.getX() << " - " << p1.getX() << ")" << " * " << "(" << p2.getY() << " - " << p1.getY() << ")"<< std::endl;

    // std::cout << "(" << p2.getX() - p1.getX()  << " * "  << (p.getY() - p1.getY()) << ")";
    // std::cout << " - ";
    // std::cout << "(" << p.getX() - p1.getX() << " * "  << (p2.getY() - p1.getY()) << ")" << std::endl;

    // std::cout << (p2.getX() - p1.getX()) * (p.getY() - p1.getY()) << " - " << ((p.getX() - p1.getX()) * (p2.getY() - p1.getY())) << std::endl;
    
    return (((p2.getX() - p1.getX()) * (p.getY() - p1.getY())) - ((p.getX() - p1.getX()) * (p2.getY() - p1.getY())));
}
