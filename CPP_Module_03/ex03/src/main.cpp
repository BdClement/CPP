/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:28:18 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/26 17:53:08 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	// Initialisation
	DiamondTrap	diamond1("Rico");
	std::cout << std::endl;
	// Actions
	diamond1.attack("un hater");
	diamond1.takeDamage(diamond1.getAttackDamage());
	diamond1.beRepaired(5);
	diamond1.highFivesGuys();
	diamond1.guardGate();
	diamond1.whoAmI();
	std::cout << std::endl;
	return (0);
}
