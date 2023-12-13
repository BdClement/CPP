/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:02:06 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/13 15:59:28 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    public:
    HumanB(std::string name);
    ~HumanB();

    void    attack();
    void    setWeapon(Weapon &arme);

    private:
    std::string m_name;
    Weapon     *m_weapon;
};

#endif
