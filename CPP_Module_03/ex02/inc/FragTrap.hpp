/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:14:55 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 16:12:44 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP__HPP
#define __FRAGTRAP__HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const & asign);
	~FragTrap();

    FragTrap & operator=(FragTrap const & equal);

    void highFivesGuys(void);
    
    private:
};

std::ostream &  operator<<(std::ostream & output, FragTrap const & input);

#endif
