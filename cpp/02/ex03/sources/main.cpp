#include "Fixed.h"
#include "Point.h"

int main()
{
    std::cout.setf(std::ios::boolalpha);
    
    Point a(-6,3);
    Point b(-5,-6);
    Point c(10,-1);
    Point point(-2,-1);
    Point point_not_in_triangle(2,-8);
    Point point_on_the_edge(0, 1.5f);
    
    bool is_in_triangle = bsp(a, b, c, point);
    std::cout << "The point " << point << " is in the triangle = "  << is_in_triangle << std::endl;
    is_in_triangle = bsp(a, b, c, point_not_in_triangle);
    std::cout << "The point " << point_not_in_triangle << " is in the triangle = "  << is_in_triangle << std::endl;
    is_in_triangle = bsp(a, b, c, point_on_the_edge);
    std::cout << "The point " << point_on_the_edge << " is in the triangle = "  << is_in_triangle << std::endl;
    return 0;
}
