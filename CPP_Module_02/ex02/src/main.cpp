/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:40:21 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/22 13:34:00 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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

// int main()
// {
//     Fixed   a(10.9f);
//     Fixed   b(7.8f);
//     Fixed   c;
//     Fixed   d(3);
//     Fixed   e;

//     e = b;

//     std::cout<<"TEST DES SURCHARGES D'OPERATEUR DE COMPARAISON"<<std::endl;
//     // Superieur / Inferieur
//     if (a > d)
//         std::cout<<a<<" est superieur a "<<d<<std::endl;
//     else
//         std::cout<<a<<" n'est pas superieur a "<<d<<std::endl;
//     if (b < d)
//         std::cout<<b<<" est inferieur a "<<d<<std::endl;
//     else
//         std::cout<<b<<" n'est pas inferieur a "<<d<<std::endl;
//     // Superieur ou egal / Inferieur ou egal
//     if (e >= b)
//         std::cout<<e<<" est superieur ou egal a "<<b<<std::endl;
//     else
//         std::cout<<e<<" n'est pas superieur ou egal a "<<b<<std::endl;
//     if (a <= d)
//         std::cout<<a<<" est inferieur ou egal a "<<d<<std::endl;
//     else
//         std::cout<<a<<" n'est pas inferieur ou egale a "<<d<<std::endl;
//     // Different / Egal
//     if (a != b)
//         std::cout<<a<<" est different de "<<b<<std::endl;
//     else
//         std::cout<<a<<" n'est pas different de "<<b<<std::endl;
//     if (e == b)
//         std::cout<<e<<" est egal a "<<b<<std::endl;
//     else
//         std::cout<<e<<" n'est pas egal a "<<b<<std::endl;
//     std::cout<<std::endl;

//     std::cout<<"TEST DES SURCHARGE D'OPERATEUR ARITHMETIQUES"<<std::endl;
//     std::cout<<a<<" + "<<b<<" == "<<a + b<<std::endl;
//     std::cout<<a<<" - "<<b<<" == "<<a - b<<std::endl;
//     std::cout<<d<<" * "<<b<<" == "<<d * b<<std::endl;
//     std::cout<<a<<" / "<<d<<" == "<<a / d<<std::endl;
//     std::cout<<std::endl;

//     std::cout<<"TEST DES SURCHARGES D'INCREMENTATION / DECREMENTATION"<<std::endl;
//     std::cout<<b<<" pre-incrementer == "<<++b<<std::endl;
//     std::cout<<b<<" pre-decrementer == "<<--b<<std::endl;
//     std::cout<<b<<" post-incrementer == "<<b++<<" puis == "<<b<<std::endl;
//     std::cout<<b<<" post-decrementer == "<<b--<<" puis == "<<b<<std::endl;
//     std::cout<<std::endl;

//     std::cout<<"TEST DES FONCTONS MEMBRES PUBLIQUES SURCHARGEES"<<std::endl;
//     std::cout<<"Le plus petit entre "<<a<<" et "<<b<<" est "<<Fixed::min(a,b)<<std::endl;
//     const Fixed&    result1 = Fixed::min(a, b);
//     std::cout<<"Le plus petit (avec la fonction const) entre "<<a<<" et "<<b<<" est "<<result1<<std::endl;

//     std::cout<<"Le plus grand entre "<<a<<" et "<<b<<" est "<<Fixed::max(a,b)<<std::endl;
//     const Fixed&    result2 = Fixed::max(a, b);
//     std::cout<<"Le plus grand (avec la fonction const) entre "<<a<<" et "<<b<<" est "<<result2<<std::endl;
//     return 0;
// }
