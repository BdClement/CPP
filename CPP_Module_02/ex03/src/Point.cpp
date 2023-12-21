/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:59:41 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/21 22:12:36 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
{

}

Point::Point(float const x, float const y) : m_x(x), m_y(y)
{
    
}

 Point::Point(Point const &asign) : m_x(asign.m_x), m_y(asign.m_y) 
 {
    
 }
// Comprendre ICI le probleme de ce constructeur par défaut 
// Point::Point(Point const & asign)
// {
//     *this = asign;
// }

Point::~Point()
{

}

Point &   Point::operator=(Point const & equal)
{
    (void)equal;
    return *this;
}

// Fixed   Point::get_x() const
// {
//     return m_x;
// }

// Fixed   Point::get_y() const
// {
//     return m_y;
// }
// Determiner si c'est mieux de retourner des float ou FIXED ?
float   Point::get_x() const 
{
    return m_x.toFloat();
}

float   Point::get_y() const
{
    return m_y.toFloat();
}

