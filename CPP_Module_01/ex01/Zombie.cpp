/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:10:52 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/18 12:42:59 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

// Constructor by default
Zombie::Zombie()
{

}

Zombie::Zombie(std::string name):m_name(name)
{
    announce();
}

Zombie::~Zombie()
{
    std::cout<<m_name<<" has been detroyed"<<std::endl;
}

void    Zombie::announce(void) const
{
    std::cout<<m_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void    Zombie::setName(std::string name)
{
    m_name = name;
}
