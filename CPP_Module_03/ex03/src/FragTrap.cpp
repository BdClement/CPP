/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:29:14 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 17:39:08 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    std::cout<<"Default FragTrap constructor called"<<std::endl;
    m_hit_points = 100;
    m_energy = 100;
    m_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"Constructor FragTrap called"<<std::endl;
    m_hit_points = 100;
    m_energy = 100;
    m_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const & asign)
{
	std::cout<<"Copy FragTrap constructor called"<<std::endl;
		*this = asign;
}

FragTrap::~FragTrap()
{
	std::cout<<"Destructor FragTrap called"<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout<<"Fragtrap "<<*this<<" gives you a high five"<<std::endl;
}

FragTrap &   FragTrap::operator=(FragTrap const & equal)
{
	std::cout<<"Copy FragTrap assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_name = equal.m_name;
		this->m_attack_damage = equal.m_attack_damage;
		this->m_energy = equal.m_energy;
		this->m_hit_points = equal.m_hit_points;
	}
	return *this;
}

// std::ostream &  operator<<(std::ostream & output, FragTrap const & input)
// {
//     output << input.getName();
//     return output;
// }
