/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:40:21 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/20 18:28:22 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// int main()
// {
//     Fixed a(3.9f);
//     Fixed b(3.8f);
//     Fixed c;

//     c = a * b;
//     std::cout<< a <<std::endl;
//     std::cout<< b <<std::endl;
//     std::cout<< c <<std::endl;
//     // if (a != b)
//     //     std::cout<<"A n'est pas egal a b"<<std::endl;
//     // else
//     //     std::cout<<"A est egal a b"<<std::endl;
//     return 0;
// }
int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}
