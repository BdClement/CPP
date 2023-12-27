/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:41:59 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/27 21:17:23 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    std::cout<<"Character default constructor called"<<std::endl;
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
    std::cout<<"Character copy constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		this->m_inventory[i] = asign.clone(i);
	this->m_name = asign.m_name;
}

Character::~Character()
{
    std::cout<<"Character destructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] != NULL)
			delete m_inventory[i];
	}
}

Character &   Character::operator=(Character const & equal)
{
	std::cout<<"Copy Character assignment operator called"<<std::endl;
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
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] == NULL)
			m_inventory[i] = m;
	}
	// Ajouter la materia passe en parametre a m_inventory si possible
}

void Character::unequip(int idx)
{
	if (m_inventory[idx] == NULL)
		std::cout<<"L'emplacement est deja vide"<<std::endl;
	else
		m_inventory[idx] = NULL;
	// Retirer la materia a l'index idx de m_inventory sans la delete
}

void Character::use(int idx, ICharacter& target)
{
	m_inventory[idx]->use(target);
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
		return m_inventory[idx]->clone();
	else
		return NULL;
}
