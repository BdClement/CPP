/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:36:19 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/12 17:52:21 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon
{
    public:
    Weapon(/* args */);
    ~Weapon();
    
    Weapon& const getType();
    void    setType(std::string type);
    
    private:
    std::string m_type;
};

#endif
