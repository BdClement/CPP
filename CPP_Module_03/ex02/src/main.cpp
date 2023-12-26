/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:28:18 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/26 16:12:34 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main()
{
	// Initialisation
	ClapTrap	claptrap1("Uno");
	ScavTrap	scavtrap1("Dos");
	FragTrap	fragtrap1("Tres");
	FragTrap	fragtrap2(fragtrap1);
	FragTrap	fragtrap3;
	fragtrap3 = fragtrap2;
	std::cout << std::endl;
	// Actions
	claptrap1.attack("Dos");
	fragtrap1.takeDamage(claptrap1.getAttackDamage());
	fragtrap1.attack("Dos");
	fragtrap2.takeDamage(fragtrap1.getAttackDamage());
	std::cout << std::endl;
	
	scavtrap1.guardGate();
	fragtrap3.highFivesGuys();
	std::cout << std::endl;

	fragtrap1.beRepaired(5);
	fragtrap2.beRepaired(3);
	std::cout << std::endl;
	return (0);
}
