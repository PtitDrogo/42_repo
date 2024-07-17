#include "Fixed.h"


int main( void ) 
{
	std::cout.setf(std::ios::boolalpha); // to print true/false instead of 1/0
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	//testing operators
	Fixed a = 5;
	Fixed const b(10);

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
	std::cout << "now Z is " << (Z) << std::endl;
	std::cout << "++Z is " << (++Z) << std::endl;
	std::cout << "now Z is " << (Z) << std::endl;
	std::cout << "Z-- is " << (Z--) << std::endl;
	std::cout << "now Z is " << (Z) << std::endl;
	std::cout << "--Z is " << (--Z) << std::endl;
	std::cout << "now Z is " << (Z) << std::endl;
	std::cout << std::endl;

	Fixed big(100);
	Fixed small(5);
	Fixed const constbig(100);
	Fixed const constsmall(5);
	std::cout << "Between big : " << big << " and small : " << small << std::endl;
	std::cout << "min is : " <<  Fixed::min(big, small) << std::endl;
	std::cout << "max is : " <<  Fixed::max(big, small) << std::endl;
	std::cout << "min of const is : " <<  Fixed::min(big, small) << std::endl;
	std::cout << "max of const is : " <<  Fixed::max(big, small) << std::endl;



	return 0;
}
