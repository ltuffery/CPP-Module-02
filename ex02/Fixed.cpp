#include "Fixed.h"
#include <iostream>
#include <cmath>
#include <ostream>

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

Fixed::Fixed( const int n ) {
	this->rawBits = n << this->fixedPoint;
}

Fixed::Fixed( const float n ) {
	this->rawBits = roundf(n * (1 << this->fixedPoint));
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
	this->rawBits = raw;
}

int Fixed::getRawBits() const {
	return this->rawBits;
}

int Fixed::toInt() const {
	return this->rawBits >> this->fixedPoint;
}

float Fixed::toFloat() const {
	return roundf(this->rawBits) / (1 << this->fixedPoint);
}

std::ostream & operator<<(std::ostream & os, Fixed fixed) {
	return os << fixed.toFloat();
}

int Fixed::operator>( const Fixed &rigth ) const {
	return this->toFloat() > rigth.toFloat();
}

int Fixed::operator<( const Fixed &rigth ) const {
	return this->toFloat() < rigth.toFloat();
}

int Fixed::operator==( const Fixed &rigth ) const {
	return this->toFloat() == rigth.toFloat();
}

int Fixed::operator!=( const Fixed &rigth ) const {
	return this->toFloat() != rigth.toFloat();
}

int Fixed::operator<=( const Fixed &rigth ) const {
	return this->toFloat() <= rigth.toFloat();
}

int Fixed::operator>=( const Fixed &rigth ) const {
	return this->toFloat() >= rigth.toFloat();
}

const Fixed Fixed::operator+( const Fixed &rigth ) const {
	return Fixed(this->toFloat() + rigth.toFloat());
}

const Fixed Fixed::operator*( const Fixed &rigth ) const {
	return this->toFloat() * rigth.toFloat();
}

const Fixed Fixed::operator-( const Fixed &rigth ) const {
	return Fixed(this->toFloat() - rigth.toFloat());
}

const Fixed Fixed::operator/( const Fixed &rigth ) const {
	return Fixed(this->toFloat() / rigth.toFloat());
}

const Fixed &Fixed::operator++( void ) {
	this->rawBits += 1;
	return *this;
}

const Fixed Fixed::operator++( int ) {
	Fixed tmp = Fixed(*this);
	this->rawBits += 1;
	return tmp;
}

const Fixed &Fixed::operator--( void ) {
	this->rawBits -= 1;
	return *this;
}

const Fixed Fixed::operator--( int ) {
	Fixed tmp = Fixed(*this);
	this->rawBits -= 1;
	return tmp;
}

Fixed &Fixed::min( Fixed &nb1, Fixed &nb2 ) {
	return nb1 < nb2 ? nb1 : nb2;
}
Fixed const &Fixed::min( Fixed const &nb1, Fixed const &nb2 ) {
	return nb1 < nb2 ? nb1 : nb2;
}
Fixed &Fixed::max( Fixed &nb1, Fixed &nb2 ) {
	return nb1 > nb2 ? nb1 : nb2;
}
Fixed const &Fixed::max( Fixed const &nb1, Fixed const &nb2 ) {
	return nb1 > nb2 ? nb1 : nb2;
}
