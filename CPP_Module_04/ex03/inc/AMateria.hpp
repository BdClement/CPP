/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:58:46 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/27 21:08:01 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA__HPP
#define __AMATERIA__HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const& asign);
	virtual ~AMateria();

	AMateria & operator=(AMateria const & equal);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	protected:
	std::string	m_type;
};

#endif
