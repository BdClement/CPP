/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:28:18 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/26 14:13:36 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	// Initialisation
	ClapTrap	claptrap1("Uno");
	ScavTrap	scavtrap1("Dos");
	ScavTrap	scavtrap2(scavtrap1);
	ScavTrap	scavtrap3;
	scavtrap3 = scavtrap2;
	std::cout << std::endl;
	// Actions
	claptrap1.attack("Dos");
	scavtrap1.takeDamage(claptrap1.getAttackDamage());
	scavtrap1.attack("Dos");
	scavtrap2.takeDamage(scavtrap1.getAttackDamage());
	std::cout << std::endl;
	
	scavtrap1.guardGate();
	scavtrap3.guardGate();
	std::cout << std::endl;

	scavtrap1.beRepaired(5);
	scavtrap2.beRepaired(3);
	std::cout << std::endl;
	return (0);
}
