#include "Fixed.h"
#include <iostream>

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&fixed == this) {
		return *this;
	}
	this->rawBits = fixed.getRawBits();
	return *this;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}
