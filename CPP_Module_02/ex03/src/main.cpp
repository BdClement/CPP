/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:40:21 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/21 22:12:22 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) 
{
    Point    a(0, 0);
    Point    b(4, 0);
    Point    c(2, 4);
    Point    in(2, 2);
    Point   out(6, 6);
   
   if (bsp(a, b, c, in))
        std::cout<<"Le point in est a l'interieur du triangle."<<std::endl;
    else
        std::cout<<"Le point in n'est pas a l'interieur du triangle."<<std::endl;
    if (bsp(a, b, c, out))
        std::cout<<"Le point out est a l'interieur du triangle."<<std::endl;
    else
        std::cout<<"Le point out n'est pas a l'interieur du triangle."<<std::endl;
    return 0;
}
