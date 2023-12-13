/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:36:19 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/13 15:47:27 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    public:
    Weapon();
    Weapon(std::string name);
    ~Weapon();

    std::string const& getType();
    void    setType(std::string type);

    private:
    std::string m_type;
};

#endif
