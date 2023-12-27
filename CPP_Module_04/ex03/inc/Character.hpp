/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:34:34 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/27 21:07:08 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER__HPP
#define __CHARACTER__HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
	Character();
	Character(std::string name);
	Character(Character const& asign);
	virtual ~Character();

	Character & operator=(Character const & equal);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	AMateria*	clone(int idx) const;
	bool		inventory_is_full();


	private:
	std::string	m_name;
	AMateria *m_inventory[4];
};

#endif
