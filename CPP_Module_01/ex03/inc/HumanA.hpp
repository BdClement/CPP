/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:48:43 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/12 18:21:53 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
    HumanA(Weapon& arme);
    ~HumanA();
    
    void    attack();

    private:
    std::string m_name;
    Weapon      m_weapon;
};

#endif
