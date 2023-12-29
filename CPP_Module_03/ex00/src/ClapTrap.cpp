/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:44:59 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/29 11:41:00 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : m_hit_points(10), m_energy(10), m_attack_damage(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hit_points(10), m_energy(10), m_attack_damage(0)
{
	std::cout<<"Constructor called"<<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"Destructor called"<<std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & asign)
{
	std::cout<<"Copy constructor called"<<std::endl;
		*this = asign;
}

ClapTrap &   ClapTrap::operator=(ClapTrap const & equal)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_name = equal.m_name;
		this->m_attack_damage = equal.m_attack_damage;
		this->m_energy = equal.m_energy;
		this->m_hit_points = equal.m_hit_points;
	}
	return *this;
}

bool	ClapTrap::hasEnergy() const
{
	if (m_energy > 0)
		return true;
	else
		return false;
}

bool	ClapTrap::hasHitPoints() const
{
	if (m_hit_points > 0)
		return true;
	else
		return false;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hasEnergy() && hasHitPoints())
	{
		std::cout<<"ClapTrap "<<*this<<" attacks "<< target<<" causing "<<m_attack_damage<<" points of damage"<<std::endl;
		--m_energy;
	}
	else
		std::cout<<"ClapTrap "<<*this<<" needs to have energy and hit points to attack "<< target<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hasEnergy() && hasHitPoints())
	{
		std::cout<<"ClapTrap "<<*this<<" takes "<<amount<<" damage"<<std::endl;
		if (amount > (unsigned int)m_hit_points)
			m_hit_points = 0;
		else
			m_hit_points -= amount;
	}
	else
		std::cout<<"ClapTrap can't take any damage because he has no energy or no hit points"<<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hasEnergy() && hasHitPoints())
	{
		std::cout<<"ClapTrap "<<*this<<" repairs himself "<<amount<<" hit points"<<std::endl;
		m_hit_points += amount;
		--m_energy;
	}
	else
		std::cout<<*this<<" is dead, it's too late"<<std::endl;
}

std::ostream &  operator<<(std::ostream & output, ClapTrap const & input)
{
    output << input.getName();
    return output;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return m_attack_damage;
}

const std::string&	ClapTrap::getName() const
{
	return m_name;
}

