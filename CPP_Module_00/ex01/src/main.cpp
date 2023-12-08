/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:50 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/08 19:58:19 by clbernar         ###   ########.fr       */
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
		{
			repertoire.newContact();
			repertoire.fillTab();
		}
		else if (cmd == "SEARCH")
		{
			int	toBeDisplayed;
			repertoire.displayTab();
			std::cout << "Entrez l'index du contact que vous souhaitez consulter";
			if (std::cin >> toBeDisplayed)
				repertoire.displayIndex(toBeDisplayed);
			else
				std::cout << "Ceci n'est pas un nombre enier valide" << std::endl;

		}
		else if (cmd != "EXIT")
			std::cout << "Mauvais commande" << std::endl;
		std::cout << std::endl;
		std::cout << "Vous avez entre la commande : " << cmd << std::endl;// TEST
	}
	return 0;
}
