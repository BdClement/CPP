/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:00:21 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/18 16:29:05 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout<<"Harl needs one, and only one valid argument"<<std::endl;
    else if ( argv[1][0] == '\0')
        std::cout<<"The argument is an empty string"<<std::endl;
    else
    {
        Harl  harl;
        harl.complain(argv[1]);
    }
    return 0;
}
