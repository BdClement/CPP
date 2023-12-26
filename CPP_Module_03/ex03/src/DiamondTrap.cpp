/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:41:19 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 18:14:35 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    std::cout<<"Default DiamondTrap constructor called"<<std::endl;
    this->m_hit_points = FragTrap::m_hit_points;
    this->m_energy = ScavTrap::m_energy;
    this->m_attack_damage = FragTrap::m_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), m_name(name)
{
    std::cout<<"Constructor DiamondTrap called"<<std::endl;
    this->m_hit_points = FragTrap::m_hit_points;
    this->m_energy = ScavTrap::m_energy;
    this->m_attack_damage = FragTrap::m_attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & asign)
{
	std::cout<<"Copy DiamondTrap constructor called"<<std::endl;
		*this = asign;
}

DiamondTrap::~DiamondTrap()
{
	std::cout<<"Destructor DiamondTrap called"<<std::endl;
}

DiamondTrap &   DiamondTrap::operator=(DiamondTrap const & equal)
{
	std::cout<<"Copy DiamondTrap assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_name = equal.m_name;
		this->m_attack_damage = equal.m_attack_damage;
		this->m_energy = equal.m_energy;
		this->m_hit_points = equal.m_hit_points;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout<<"DiamondTrap name is "<<this->getName()<<std::endl;
    std::cout<<"ClapTrap subobject name is "<<*this<<std::endl;
}

const std::string&	DiamondTrap::getName() const
{
	return m_name;
}

// std::ostream &  operator<<(std::ostream & output, DiamondTrap const & input)
// {
//     output << input.getName();
//     return output;
// }
