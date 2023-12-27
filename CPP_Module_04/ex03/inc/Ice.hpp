/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:39:13 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/27 20:45:44 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE__HPP
#define __ICE__HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
	Ice();
	Ice(Ice const& asign);
	~Ice();

	Ice & operator=(Ice const & equal);

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);

	private:
};

#endif
