/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:20:36 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/13 15:47:31 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//Constructor by default
Weapon::Weapon()
{

}

Weapon::Weapon(std::string name) : m_type(name)
{

}

// Destructor
Weapon::~Weapon()
{

}

std::string const& Weapon::getType()
{
	return m_type;
}

void	Weapon::setType(std::string type)
{
	m_type = type;
}
