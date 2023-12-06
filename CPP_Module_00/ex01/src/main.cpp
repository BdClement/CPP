/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:50 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/06 19:39:09 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.hpp"

int	main()
{
	std::string	cmd;

	std::cout << "Entrez une commande : ";
	std::cin >> cmd;
	std::cout << std::endl;
	std::cout << "Vous avez entre la commande : " << cmd << std::endl;
	return 0;
}
