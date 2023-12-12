/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:04:59 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/12 18:12:16 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

void    HumanB:: attack()
{
    std::cout<< m_name << "attacks with their " << m_weapon.getType().m_type << std::endl;
}
