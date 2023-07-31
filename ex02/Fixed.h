#ifndef FIXED_H
# define FIXED_H

#include <ostream>

class Fixed {

	private:
		int comma;
		const static int bits = 8; 

	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float n );
		Fixed( const Fixed &fixed );
		~Fixed( void );
		Fixed &operator=( const Fixed &fixed );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed &min( Fixed &nb1, Fixed &nb2 );
		static Fixed const &min( Fixed const &nb1, Fixed const &nb2 );
		static Fixed &max( Fixed &nb1, Fixed &nb2 );
		static Fixed const &max( Fixed const &nb1, Fixed const &nb2 );

		int operator>( const Fixed &rigth ) const;
		int operator<( const Fixed &rigth ) const;
		int operator<=( const Fixed &rigth ) const;
		int operator>=( const Fixed &rigth ) const;
		int operator==( const Fixed &rigth ) const;
		int operator!=( const Fixed &rigth ) const;

		const Fixed operator+( const Fixed &rigth ) const;
		const Fixed operator-( const Fixed &rigth ) const;
		const Fixed operator*( const Fixed &rigth ) const;
		const Fixed operator/( const Fixed &rigth ) const;

};

const Fixed &operator++( Fixed &fixed );
const Fixed operator++( Fixed &fixed, int );
const Fixed &operator--( Fixed &fixed );
const Fixed operator--( Fixed &fixed, int );

std::ostream & operator<<(std::ostream & os, Fixed fixed);

#endif
