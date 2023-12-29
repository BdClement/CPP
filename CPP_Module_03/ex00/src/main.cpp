/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:28:18 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/29 11:41:45 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	// Initialisation
	ClapTrap	Claptrap1("Uno");
	ClapTrap	Claptrap2("Dos");
	ClapTrap	Claptrap3(Claptrap1);
	ClapTrap	Claptrap4;
	Claptrap4 = Claptrap2;
	std::cout << std::endl;

	std::cout << Claptrap1 << std::endl;
	std::cout << Claptrap2 << std::endl;
	std::cout << Claptrap3 << std::endl;
	std::cout << Claptrap4 << std::endl;
	std::cout << std::endl;

	// Actions
	Claptrap1.attack("Dos");
	Claptrap2.takeDamage(Claptrap1.getAttackDamage());
	Claptrap4.attack("Uno");
	Claptrap3.takeDamage(Claptrap4.getAttackDamage());
	std::cout << std::endl;
	Claptrap2.beRepaired(5);
	Claptrap3.beRepaired(3);
	std::cout << std::endl;
	return (0);
}
