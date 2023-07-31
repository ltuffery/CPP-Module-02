#include "Fixed.h"
#include <iostream>
#include <cmath>
#include <ostream>

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->comma = 0;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( const int n ) {
	this->comma = n << this->bits;
}

Fixed::Fixed( const float n ) {
	this->comma = roundf(n * (1 << this->bits));
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&fixed == this) {
		return *this;
	}
	this->comma = fixed.getRawBits();
	return *this;
}

void Fixed::setRawBits(const int raw) {
	this->comma = raw;
}

int Fixed::getRawBits() const {
	return this->comma;
}

int Fixed::toInt() const {
	return this->comma >> this->bits;
}

float Fixed::toFloat() const {
	return roundf(this->comma) / (1 << this->bits);
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
	this->comma += 1;
	return *this;
}

const Fixed Fixed::operator++( int ) {
	Fixed tmp = Fixed(*this);
	this->comma += 1;
	return tmp;
}

const Fixed &Fixed::operator--( void ) {
	this->comma -= 1;
	return *this;
}

const Fixed Fixed::operator--( int ) {
	Fixed tmp = Fixed(*this);
	this->comma -= 1;
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
