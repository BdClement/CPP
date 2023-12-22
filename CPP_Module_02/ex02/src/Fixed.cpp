/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:40:11 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/22 13:18:31 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>

const int Fixed::m_frac_part = 8;

/////////////////////Constructor & Destructor ////////////////////////
Fixed::Fixed() : m_value(0)
{

}

Fixed::Fixed(Fixed const & asign)
{
    *this = asign;
}

// Revient a multiplier par 2 puissance 8 notre int
Fixed::Fixed(int const value)
{
    m_value = value << m_frac_part;
    // if (m_value > std::numeric_limits<int>::max())
    //     m_value = std::numeric_limits<int>::max();
    // else if (m_value < std::numeric_limits<int>::min())
    //     m_value = std::numeric_limits<int>::min();
}

// Pour convertir le float on ne peux pas seulement decaler les bits puisque le
// décalage ne prend en compte que la partie entiere du float
// On multiplie donc en passant par un double pour pouvoir arrondir via round()
// a l'entier le plus proche et gagner en précision
Fixed::Fixed(float const value)
{
    // double doubleValue = static_cast<double>(value) * (1 << m_frac_part);
    // double roundedValue = std::round(doubleValue);
    float roundedValue = roundf(value * (1 << m_frac_part));
    m_value = static_cast<int>(roundedValue);
    // if (m_value > std::numeric_limits<int>::max())
    //     m_value = std::numeric_limits<int>::max();
    // else if (m_value < std::numeric_limits<int>::min())
    //     m_value = std::numeric_limits<int>::min();
}

Fixed::~Fixed()
{

}

//////////////////////// Methodes membres //////////////////////////////
int Fixed::getRawBits(void) const
{
    return m_value;
}

void Fixed::setRawBits(int const raw)
{
    m_value = raw;
}

// Le decalage des bits ne peut pas etre effectué sur un float car le decalage
// ne prend en compte que la partie entière du float
float Fixed::toFloat( void ) const
{
    return (static_cast<float>(m_value) / (1 << m_frac_part));
}

// Le decalage de bit vers la droite revient a diviser par 2 puissance 8
int Fixed::toInt( void ) const
{
    // return (m_value / std::pow(2, m_frac_part));// Equivalent
    return (m_value >> m_frac_part);

}

// Fonction surcharge d'operateur
std::ostream &  operator<<(std::ostream & output, Fixed const & input)
{
    output << input.toFloat();
    return output;
}

Fixed &   Fixed::operator=(Fixed const & equal)
{
    if (this != &equal)
        this->m_value = equal.getRawBits();
    return *this;
}

// Comparaison
bool Fixed::operator<(Fixed const& value) const
{
    if (this->getRawBits() < value.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator>(Fixed const& value) const
{
    if (this->getRawBits() > value.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<=(Fixed const& value) const
{
    if (this->getRawBits() <= value.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator>=(Fixed const& value) const
{
    if (this->getRawBits() >= value.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator==(Fixed const& value) const
{
    if (this->getRawBits() == value.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator!=(Fixed const& value) const
{
    if (this->getRawBits() != value.getRawBits())
        return true;
    else
        return false;
}

// Arithmetique
Fixed Fixed::operator+(Fixed const& value)
{
    Fixed   result;
    result.setRawBits(this->getRawBits() + value.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const& value)
{
    Fixed   result;
    result.setRawBits(this->getRawBits() - value.getRawBits());
    return result;
}

Fixed Fixed::operator*(Fixed const& value)
{
    return (Fixed(this->toFloat() * value.toFloat()));
}

Fixed Fixed::operator/(Fixed const& value)
{
    return (Fixed(this->toFloat() / value.toFloat()));
}

// Incrémentation
Fixed   Fixed::operator++( void )
{
    m_value++;
    return (*this);
}

Fixed   Fixed::operator++( int )
{
    Fixed   temp(*this);
    ++(*this);
    return (temp);
}

Fixed   Fixed::operator--( void )
{
    m_value--;
    return (*this);
}

Fixed   Fixed::operator--( int )
{
    Fixed   temp(*this);
    --(*this);
    return (temp);
}

// Reste des methodes
Fixed&  Fixed::min(Fixed &value1, Fixed &value2)
{
    return ((value1 < value2) ? value1 : value2);
}

const Fixed&    Fixed::min(Fixed const& value1, Fixed const& value2)
{
    return ((value1 < value2) ? value1 : value2);
}
Fixed&  Fixed::max(Fixed &value1, Fixed &value2)
{
    return ((value1 > value2) ? value1 : value2);
}

const Fixed&    Fixed::max(Fixed const& value1, Fixed const& value2)
{
    return ((value1 > value2) ? value1 : value2);
}
