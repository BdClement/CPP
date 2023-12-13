/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:11:42 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/13 15:43:46 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

// Constructor by default
HumanA::HumanA(std::string name, Weapon& arme): m_name(name), m_weapon(arme)
{

}

// Destructor
HumanA::~HumanA()
{

}

void    HumanA:: attack()
{
    std::cout<< m_name << " attacks with their " << m_weapon.getType() << std::endl;
}
