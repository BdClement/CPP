/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:40:11 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/22 12:01:00 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::m_frac_part = 8;

Fixed::Fixed() : m_value(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(Fixed const & asign)
{
    std::cout<<"Copy constructor called"<<std::endl;
    // this->setRawBits(asign.getRawBits());
    *this = asign;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed &   Fixed::operator=(Fixed const & equal)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &equal)
        this->m_value = equal.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return m_value;
}

void Fixed::setRawBits(int const raw)
{
    m_value = raw;
    // std::cout<<"setRawBits member function called"<<std::endl;
}
