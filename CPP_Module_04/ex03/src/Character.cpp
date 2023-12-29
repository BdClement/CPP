/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:41:59 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/29 22:46:01 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"

Character::Character()
{
    // std::cout<<"Character default constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character(std::string name) : m_name(name)
{
    std::cout<<"Character "<<name<<" constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character(Character const& asign)
{
    // std::cout<<"Character copy constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (asign.m_inventory[i] != NULL)
			this->m_inventory[i] = asign.clone(i);
		else
			this->m_inventory[i] = NULL;
	}
	this->m_name = asign.m_name;
}

Character::~Character()
{
    // std::cout<<"Character destructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] != NULL)
			m_inventory[i] = NULL;
	}
}

Character &   Character::operator=(Character const & equal)
{
	// std::cout<<"Copy Character assignment operator called"<<std::endl;
	if (this != &equal)
	{
		// Liberation de l'ancien inventory de mon Character
		for (int i = 0; i < 4; i++)
		{
			if (m_inventory[i] != NULL)
				delete m_inventory[i];
		}
		// Affectation de mon inventaire
		for (int i = 0; i < 4; i++)
			this->m_inventory[i] = equal.clone(i);
		// Gestion de la copie profonde de m_inventory
		this->m_name = equal.m_name;
	}
	return *this;
}

std::string const & Character::getName() const
{
	return m_name;
}

void Character::equip(AMateria* m)
{
	if (inventory_is_full())
	{
		std::cout<<"L'inventaire est full"<< std::endl;
		return ;
	}
	else if (m == NULL)
	{
		std::cout<<"Il n'y a pas de materia a equiper"<< std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] == NULL)
		{
			m_inventory[i] = m;
			return ;
		}
	}
	std::cout<<this->m_name<<" n'a pas pus 'equiper de la materia"<< std::endl;
}

void Character::unequip(int idx)
{
	if (m_inventory[idx] == NULL)
		std::cout<<"L'emplacement est deja vide"<<std::endl;
	else
	{
		m_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (m_inventory[idx] != NULL)
		m_inventory[idx]->use(target);
	else
		std::cout<<"Nothing to use here"<<std::endl;
}

bool	Character::inventory_is_full()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] == NULL)
			return false;
	}
	return true;
}

AMateria*	Character::clone(int idx) const
{
	if (m_inventory[idx] != NULL)
	{
		AMateria *tmp = m_inventory[idx]->clone();
		add_to_historic(tmp);
		return tmp;
	}
	else
		return NULL;
}

void	Character::add_to_historic(AMateria* m) const
{
	for (int i = 0; i < 1000; i++)
	{
		if (historic[i] == NULL)
		{
			historic[i] = m;
			return ;
		}
	}
	std::cout<<"Warning : Historic is not big enough !"<<std::endl;
}

