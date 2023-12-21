/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:53:11 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/21 22:12:28 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT__HPP
#define __POINT__HPP

#include "Fixed.hpp"

class Point{
   
    public:
    Point();
    Point(float const x, float const y);
    Point(Point const & asign);
    ~Point();

    Point & operator=(Point const & equal);
    float   get_x() const ;
    float   get_y() const ;
    // Fixed   get_x() const;
    // Fixed   get_y() const; ??

    private:
        // Attributs membres de la classe
    Fixed const   m_x;
    Fixed const   m_y;
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
