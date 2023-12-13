/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:04:59 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/13 16:05:29 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

// Constructor by default
HumanB::HumanB(std::string name):m_name(name)
{
    m_weapon = NULL;
}

// Destructor
HumanB::~HumanB()
{

}

void    HumanB::setWeapon(Weapon &arme)
{
    m_weapon = &arme;
}

void    HumanB:: attack()
{
    if (m_weapon)
        std::cout<< m_name << " attacks with their " << m_weapon->getType() << std::endl;
    else
        std::cout<< m_name << " has no weapon" << std::endl;
}
