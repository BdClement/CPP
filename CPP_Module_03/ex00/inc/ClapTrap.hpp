/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:41:59 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/22 20:13:35 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP__HPP
#define __CLAPTRAP__HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & asign);
	~ClapTrap();

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	bool			hasEnergy() const;
	bool			hasHitPoints() const;
	unsigned int	getAttackDamage() const;
	const std::string&	getName() const;

	ClapTrap & operator=(ClapTrap const & equal);

	private:
	std::string		m_name;
	int				m_hit_points;
	int				m_energy;
	int				m_attack_damage;
};

std::ostream &  operator<<(std::ostream & output, ClapTrap const & input);

#endif
