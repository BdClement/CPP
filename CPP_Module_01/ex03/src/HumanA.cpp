/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:11:42 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/12 18:12:13 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

void    HumanA:: attack()
{
    std::cout<< m_name << "attacks with their " << m_weapon.getType().m_type << std::endl;
}
