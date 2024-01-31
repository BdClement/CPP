/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:12:35 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/31 14:44:47 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout<<"Error : could not open file."<<std::endl;
	else
	{
		std::ifstream input(argv[1], std::ifstream::in);
		try
		{
			if (!input.is_open())
				throw std::exception();
			if (input.peek() == std::ifstream::traits_type::eof())
			{
				std::cout<<"File is empty"<<std::endl;
				return 0;
			}
			BitcoinExchange	btc_exchange;
			std::string	line;
			std::getline(input, line);
			btc_exchange.clean_string(line);
			if (line != "date | value")
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
