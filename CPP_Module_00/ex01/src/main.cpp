/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:50 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/15 18:45:47 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook repertoire;
	std::string	cmd;
	std::cout<< "Bienvenue dans PhoneBook !" <<std::endl<<std::endl;

	while (cmd not_eq "EXIT")
	{
		std::cout << "Entrez une commande (ADD, SEARCH ou EXIT): ";
		if (!std::getline(std::cin, cmd))
			exit(-1);

		if (cmd == "ADD")
			repertoire.newContact();
		else if (cmd == "SEARCH")
			repertoire.Search();
		else if (cmd != "EXIT")
			std::cout << "Mauvaise commande" << std::endl << std::endl;
	}
	return 0;
}
