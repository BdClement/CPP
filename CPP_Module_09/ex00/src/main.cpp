/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:12:35 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/30 19:28:26 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>

int	main(int argc, char **argv)
{
	// Test d'ouverture du fichier input sinon SALAM
	// Creation d'un objet Bitcoin exchange
	// Lecture du fichier input ligne par ligne avec get line
	// Appel d'une methode membre a chaque fois qui recoit la string lue
	if (argc != 2)
		std::cout<<"Error : could not open file."<<std::endl;
	else
	{
		std::ifstream input(argv[1], std::ifstream::in);
		try
		{
			if (!input.is_open())
				throw std::exception();
			BitcoinExchange	btc_exchange;
			// btc_exchange.display_map();// Test
			std::string	line;
			std::getline(input, line);
			btc_exchange.clean_string(line);
			if (line != "date | value") // Gestion de la premiere ligne
				btc_exchange.run_exchange(line);
			while (std::getline(input, line))
				btc_exchange.run_exchange(line);
		}
		catch (const std::exception& )
		{
			std::cerr<<"Error : could not open file."<<std::endl;
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}

// TEST CONSTRUCTEURS EN METTANT MA MAP EN PUBLIC
// int	main()
// {
// 	BitcoinExchange	test1;
// 	test1.m_data_base.insert(std::pair<std::string, double>("Salut", 10));
// 	test1.m_data_base.insert(std::pair<std::string, double>("ca", 0.5));
// 	test1.m_data_base.insert(std::pair<std::string, double>("va ?", -12.5));

// 	BitcoinExchange	test2(test1);
// 	std::map<std::string, double>::iterator it = test1.m_data_base.begin();
// 	test1.m_data_base.erase(it);
// 	BitcoinExchange	test3;
// 	test3 = test1;
// 	test3.m_data_base.insert(std::pair<std::string, double>("Wesh", 100));

// 	std::cout<<"Test 1\n"<<std::endl;
// 	for(std::map<std::string, double>::iterator it = test1.m_data_base.begin(); it != test1.m_data_base.end(); ++it)
// 		std::cout<<"Cle "<<it->first<<" Valeur "<<it->second<<std::endl;
// 	std::cout<<"\nTest 2"<<std::endl;
// 	for(std::map<std::string, double>::iterator it = test2.m_data_base.begin(); it != test2.m_data_base.end(); ++it)
// 		std::cout<<"Cle "<<it->first<<" Valeur "<<it->second<<std::endl;
// 	std::cout<<"\nTest 3"<<std::endl;
// 	for(std::map<std::string, double>::iterator it = test3.m_data_base.begin(); it != test3.m_data_base.end(); ++it)
// 		std::cout<<"Cle "<<it->first<<" Valeur "<<it->second<<std::endl;
// 	return 0;
// }
