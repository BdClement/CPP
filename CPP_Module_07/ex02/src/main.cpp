/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:54:04 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/23 11:20:51 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Array.hpp"

int	main()
{
	// Array<int>	test1(5);
	// try
	// {
	// 	std::cout<<test1[3]<<std::endl;
	// 	std::cout<<test1[7]<<std::endl;
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cerr << "Erreur d'indexation hors limites : " << e.what() << std::endl;
	// }
	Array<std::string>	test;
	Array<std::string>	test1;
	Array<std::string>	test2(50);
	Array<std::string>	test3(test2);
	test1 = test3;
	try
	{
		std::cout<<"\n\n"<<test1[3]<<std::endl;
		std::cout<<test3[3]<<std::endl;
		std::cout<<test2[7]<<std::endl;
		std::cout<<test[7]<<std::endl;
		// std::cout<<test2[-8]<<"\n\n"<<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	test2[2] = "Salut";
	std::cout<<test2[2]<<std::endl;
	std::cout<<test3[2]<<std::endl;
	return 0;
}
