/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:10:52 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/12 13:27:50 by Enfoirax         ###   ########.fr       */
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
