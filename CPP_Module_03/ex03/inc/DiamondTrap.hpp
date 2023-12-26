/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:25:05 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 17:46:45 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP__HPP
#define __DIAMONDTRAP__HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const & asign);
	~DiamondTrap();

    DiamondTrap & operator=(DiamondTrap const & equal);
    const std::string&      getName() const;
    void                    whoAmI();
    
    private:
    std::string		m_name;
};

// std::ostream &  operator<<(std::ostream & output, ClapTrap const & input);

#endif
