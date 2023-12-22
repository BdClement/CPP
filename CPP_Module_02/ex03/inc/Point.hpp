/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:53:11 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/22 13:30:46 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT__HPP
#define __POINT__HPP

#include "Fixed.hpp"

class Point
{
    public:
    Point();
    Point(float const x, float const y);
    Point(Point const & asign);
    ~Point();

    Point & operator=(Point const & equal);

    Fixed   get_x() const;
    Fixed   get_y() const;

    private:
    Fixed const   m_x;
    Fixed const   m_y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
