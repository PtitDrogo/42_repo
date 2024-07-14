#include "Fixed.h"


int main( void ) 
{
	std::cout.setf(std::ios::boolalpha); // to print true/false instead of 1/0
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	//testing operators
	std::cout << std::endl << "MY TESTS "<< std::endl;
	std::cout << "a is " << a << " b is " << b << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a + b is " << (a + b) << std::endl;
	std::cout << "a - b is " << (a - b) << std::endl;
	std::cout << "a * b is " << (a * b) << std::endl;
	std::cout << "a / b is " << (a / b) << std::endl;
	
	Fixed Z(42);

	std::cout << "Z++ is " << (Z++) << std::endl;
	std::cout << "now Z is " << (Z.toFloat()) << std::endl;
	std::cout << "++Z is " << (++Z) << std::endl;
	std::cout << "now Z is " << (Z.toFloat()) << std::endl;
	std::cout << "Z-- is " << (Z--) << std::endl;
	std::cout << "now Z is " << (Z.toFloat()) << std::endl;
	std::cout << "--Z is " << (--Z) << std::endl;
	std::cout << "now Z is " << (Z.toFloat()) << std::endl;
	std::cout << std::endl;




	return 0;
}
