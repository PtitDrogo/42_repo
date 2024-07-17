#include "Fixed.h"
#include "Point.h"

int main()
{
    Point a(1,1);
    Point b(5,5);
    Point c(10,10);
    Point point(0,0);
    
    bsp(a, b, c, point);
    return 0;
}
