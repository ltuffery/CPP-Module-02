#ifndef FIXED_H
# define FIXED_H

#include <ostream>

class Fixed {

	private:
		int rawBits;
		const static int fixedPoint = 8; 

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

};

std::ostream & operator<<(std::ostream & os, Fixed fixed);

#endif
