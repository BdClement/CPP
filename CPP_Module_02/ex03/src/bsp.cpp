/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:18:58 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/21 22:12:34 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// Methodes du produit vectoriel
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // Test OK
    // std::cout<<"Point A = "<< a.get_x() << " , "<<a.get_y()<<std::endl;
    // std::cout<<"Point A = "<< a.get_x() << " , "<<a.get_y()<<std::endl;
    // std::cout<<"Point B = "<< b.get_x() << " , "<<b.get_y()<<std::endl;
    // std::cout<<"Point C = "<< c.get_x() << " , "<<c.get_y()<<std::endl;
    // std::cout<<"Point Point = "<< point.get_x() << " , "<<point.get_y()<<std::endl<<std::endl<<std::endl;
    //Calcul des vecteurs issus du triangle
    Point   ab(b.get_x() - a.get_x(), b.get_y() - a.get_y());
    Point   bc(c.get_x() - b.get_x(), c.get_y() - b.get_y());
    Point   ca(a.get_x() - c.get_x(), a.get_y() - c.get_y());
    Point   aPoint(point.get_x() - a.get_x(), point.get_y() - a.get_y());
    Point   bPoint(point.get_x() - b.get_x(), point.get_y() - b.get_y());
    Point   cPoint(point.get_x() - c.get_x(), point.get_y() - c.get_y());
    // std::cout<<"Point AB = "<< ab.get_x() << " , "<<ab.get_y()<<std::endl;
    // std::cout<<"Point BC = "<< bc.get_x() << " , "<<bc.get_y()<<std::endl;
    // std::cout<<"Point CA = "<< ca.get_x() << " , "<<ca.get_y()<<std::endl;
    // std::cout<<"Point APoint = "<< aPoint.get_x() << " , "<<aPoint.get_y()<<std::endl;
    // std::cout<<"Point BPoint = "<< bPoint.get_x() << " , "<<bPoint.get_y()<<std::endl;
    // std::cout<<"Point CPoint = "<< cPoint.get_x() << " , "<<cPoint.get_y()<<std::endl;
    // Calcul des produits vectoriels
    Fixed p_ABAP = (ab.get_x() * aPoint.get_y() - ab.get_y() * aPoint.get_x());
    Fixed p_BCBP = (bc.get_x() * bPoint.get_y() - bc.get_y() * bPoint.get_x());
    Fixed p_CACP = (ca.get_x() * cPoint.get_y() - ca.get_y() * cPoint.get_x());
    // std::cout<<" Produit vectoriel ABAP = "<<p_ABAP<<std::endl;
    // std::cout<<" Produit vectoriel BCBP = "<<p_BCBP<<std::endl;
    // std::cout<<" Produit vectoriel CACP = "<<p_CACP<<std::endl;
    // Interpretation des résultats des produits vectoriels
    if (p_ABAP > 0 && p_BCBP > 0 && p_CACP > 0)
        return true;
    else if (p_ABAP < 0 && p_BCBP < 0 && p_CACP < 0)
        return true;
    else
        return false;
}
