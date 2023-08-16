#ifndef FIXED_H
# define FIXED_H

class Fixed {

	private:
		int rawBits;
		const static int fixedPoint = 8; 

	public:
		Fixed( void );
		Fixed( const Fixed &fixed );
		~Fixed( void );
		Fixed &operator=( const Fixed &fixed );
		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif
