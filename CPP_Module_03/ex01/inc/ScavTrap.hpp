/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:07:41 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 14:14:21 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP__HPP
#define __SCAVTRAP__HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
    public :
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const & asign);
	~ScavTrap();

    ScavTrap & operator=(ScavTrap const & equal);
    void			attack(const std::string& target);
    void            guardGate();

    private :
};

std::ostream &  operator<<(std::ostream & output, ScavTrap const & input);

#endif
