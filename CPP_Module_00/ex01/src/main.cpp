/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:50 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/11 14:36:29 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.hpp"

void	displayResizedStr(std::string resized)
{
	if(resized.size() > 10)
	{
		resized.resize(9);
		resized.insert(9, ".");
	}
	else if(resized.size() < 10)
	{
		while (resized.size() != 10)
			resized.insert(0, " ");
	}
	std::cout << resized;
}

int	main()
{
	PhoneBook repertoire;
	std::string	cmd;
	std::cout<< "Bienvenue dans PhoneBook !" <<std::endl<<std::endl;

	while (cmd not_eq "EXIT")
	{
		std::cout << "Entrez une commande (ADD, SEARCH ou EXIT): ";
		std::getline(std::cin, cmd);

		if (cmd == "ADD")
			repertoire.executeAdd();
		else if (cmd == "SEARCH")
			repertoire.excecuteSearch();
		else if (cmd != "EXIT")
			std::cout << "Mauvaise commande" << std::endl << std::endl;
	}
	return 0;
}
