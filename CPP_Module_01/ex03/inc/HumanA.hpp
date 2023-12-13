/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:48:43 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/13 15:48:35 by clbernar         ###   ########.fr       */
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
    HumanA(std::string name, Weapon& arme);
    ~HumanA();

    void    attack();

    private:
    std::string m_name;
    Weapon&      m_weapon;
};

#endif
