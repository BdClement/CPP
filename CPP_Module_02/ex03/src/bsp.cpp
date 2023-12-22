/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:18:58 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/22 13:27:23 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// Methodes du produit vectoriel
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // TEST
    // std::cout<<"Point A = "<< a.get_x() << " , "<<a.get_y()<<std::endl;
    // std::cout<<"Point A = "<< a.get_x() << " , "<<a.get_y()<<std::endl;
    // std::cout<<"Point B = "<< b.get_x() << " , "<<b.get_y()<<std::endl;
    // std::cout<<"Point C = "<< c.get_x() << " , "<<c.get_y()<<std::endl;
    // std::cout<<"Point Point = "<< point.get_x() << " , "<<point.get_y()<<std::endl<<std::endl<<std::endl;
    //CALCUL DES VECTEURS ISSU DU TRIANGLE
    Point   ab((b.get_x() - a.get_x()).toFloat(), (b.get_y() - a.get_y()).toFloat());
    Point   bc((c.get_x() - b.get_x()).toFloat(), (c.get_y() - b.get_y()).toFloat());
    Point   ca((a.get_x() - c.get_x()).toFloat(), (a.get_y() - c.get_y()).toFloat());
    Point   aPoint((point.get_x() - a.get_x()).toFloat(), (point.get_y() - a.get_y()).toFloat());
    Point   bPoint((point.get_x() - b.get_x()).toFloat(), (point.get_y() - b.get_y()).toFloat());
    Point   cPoint((point.get_x() - c.get_x()).toFloat(), (point.get_y() - c.get_y()).toFloat());
    // std::cout<<"Point AB = "<< ab.get_x() << " , "<<ab.get_y()<<std::endl;
    // std::cout<<"Point BC = "<< bc.get_x() << " , "<<bc.get_y()<<std::endl;
    // std::cout<<"Point CA = "<< ca.get_x() << " , "<<ca.get_y()<<std::endl;
    // std::cout<<"Point APoint = "<< aPoint.get_x() << " , "<<aPoint.get_y()<<std::endl;
    // std::cout<<"Point BPoint = "<< bPoint.get_x() << " , "<<bPoint.get_y()<<std::endl;
    // std::cout<<"Point CPoint = "<< cPoint.get_x() << " , "<<cPoint.get_y()<<std::endl;
    // CALCUL DES PRODUITS VECTORIELS
    Fixed p_ABAP = (ab.get_x() * aPoint.get_y() - ab.get_y() * aPoint.get_x());
    Fixed p_BCBP = (bc.get_x() * bPoint.get_y() - bc.get_y() * bPoint.get_x());
    Fixed p_CACP = (ca.get_x() * cPoint.get_y() - ca.get_y() * cPoint.get_x());
    // std::cout<<" Produit vectoriel ABAP = "<<p_ABAP<<std::endl;
    // std::cout<<" Produit vectoriel BCBP = "<<p_BCBP<<std::endl;
    // std::cout<<" Produit vectoriel CACP = "<<p_CACP<<std::endl;
    // INTERPRETATION DES RESULTATS DES PRODUITS VECTORIELS
    if (p_ABAP > 0 && p_BCBP > 0 && p_CACP > 0)
        return true;
    else if (p_ABAP < 0 && p_BCBP < 0 && p_CACP < 0)
        return true;
    else
        return false;
}
