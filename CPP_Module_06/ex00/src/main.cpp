/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:54:25 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/16 20:01:21 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout<<"This program needs an argument"<<std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
