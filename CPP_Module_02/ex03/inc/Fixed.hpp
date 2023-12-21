/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:37 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/21 22:12:25 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__HPP
#define __FIXED__HPP

#include <iostream>

class Fixed
{
    public:
    Fixed();
    Fixed(Fixed const & asign);
    Fixed(int const value);
    Fixed(float const value);
    ~Fixed();

    //Surcharge d'opérateur
    Fixed & operator=(Fixed const & equal);
    // Comparaison
    bool operator<(Fixed const& value)const ;
    bool operator>(Fixed const & value)const ;
    bool operator<=(Fixed const & value)const ;
    bool operator>=(Fixed const & value)const ;
    bool operator==(Fixed const & value)const ;
    bool operator!=(Fixed const & value)const ;
    // Arithmetique
    Fixed operator+(Fixed const& value);
    Fixed operator-(Fixed const& value);
    Fixed operator*(Fixed const& value);
    Fixed operator/(Fixed const& value);
    // Incrémentation
    Fixed operator++( void );
    Fixed operator++( int );
    Fixed operator--( void );
    Fixed operator--( int );

    // Methodes
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed&   min(Fixed &value1, Fixed &value2);
    const static Fixed&   min(Fixed const& value1, Fixed const& value2);
    static Fixed&   max(Fixed &value1, Fixed &value2);
    const static Fixed&   max(Fixed const& value1, Fixed const& value2);

    private:
    int                 m_value;
    int const static    m_frac_part;
        
};

std::ostream &  operator<<(std::ostream & output, Fixed const & input);

#endif
