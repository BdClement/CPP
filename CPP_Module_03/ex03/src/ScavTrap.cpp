/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:16:41 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 17:39:05 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout<<"Default ScavTrap constructor called"<<std::endl;
    m_hit_points = 100;
    m_energy = 50;
    m_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"Constructor ScavTrap called"<<std::endl;
    m_hit_points = 100;
    m_energy = 50;
    m_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & asign)
{
	std::cout<<"Copy ScavTrap constructor called"<<std::endl;
		*this = asign;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"Destructor ScavTrap called"<<std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hasEnergy() && hasHitPoints())
	{
		std::cout<<"ScavTrap "<<*this<<" attacks "<< target<<" causing "<<m_attack_damage<<" points of damage"<<std::endl;
		--m_energy;
		--m_hit_points;
	}
	else
		std::cout<<"ScavTrap "<<*this<<" needs to have energy and hit points to attack "<< target<<std::endl;
}

ScavTrap &   ScavTrap::operator=(ScavTrap const & equal)
{
	std::cout<<"Copy ScavTrap assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_name = equal.m_name;
		this->m_attack_damage = equal.m_attack_damage;
		this->m_energy = equal.m_energy;
		this->m_hit_points = equal.m_hit_points;
	}
	return *this;
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<m_name<<" is now in Gate keeper mode"<<std::endl;
}

// std::ostream &  operator<<(std::ostream & output, ScavTrap const & input)
// {
//     output << input.getName();
//     return output;
// }
