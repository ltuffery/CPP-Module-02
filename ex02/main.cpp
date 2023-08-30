#include <iostream>
#include "Fixed.h"

int main( void ) {
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
		std::cout << Fixed::min( a, b ) << std::endl;
	}
	std::cout << "\n-----------------\n" << std::endl;
	{
		Fixed a(2);
		Fixed b(3);

		if (a < b)
			std::cout << "a < b" << std::endl;
		if (a > b)
			std::cout << "a > b" << std::endl;
		if (a <= b)
			std::cout << "a <= b" << std::endl;
		if (a >= b)
			std::cout << "a >= b" << std::endl;
		if (a == b)
			std::cout << "a == b" << std::endl;
		if (a != b)
			std::cout << "a != b" << std::endl;
	}
	std::cout << "\n-----------------\n" << std::endl;
	{
		Fixed a(2);
		Fixed const b(5.5f);

		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
	}
	std::cout << "\n-----------------\n" << std::endl;
	{
		Fixed a(3);

		std::cout << a++ << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << --a << std::endl;
	}
	return 0;
}
