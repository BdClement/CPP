/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:00:21 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/14 19:52:32 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout<<"Harl needs one, and only one argument"<<std::endl;
    else
    {
        Harl  harl;
        harl.complain(argv[1]);
    }
    return 0;
}
