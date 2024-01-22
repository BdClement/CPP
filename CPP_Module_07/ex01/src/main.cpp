/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:55:39 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/22 16:26:00 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	int		tab_int[5] = {0, 1, 2, 3, 4};
	double	tab_double[8] = {0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18};
	std::string	tab_string[3] = {"Looks like", "It is", "Working"};

	std::cout<<"Affichage d'un tableau d'int :"<<std::endl;
	iter<int, void>(tab_int, 5, print<int>);
	std::cout<<"\n\nAffichage d'un tableau de double :"<<std::endl;
	iter<double, double>(tab_double, 8, printDouble<double>);
	std::cout<<"\n\nAffichage d'un tableau de string :"<<std::endl;
	iter<std::string, void>(tab_string, 3, printString<std::string>);
	return 0;
}
