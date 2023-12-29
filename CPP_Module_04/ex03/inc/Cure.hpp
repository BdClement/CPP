/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:53:08 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/29 19:36:47 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE__HPP
#define __CURE__HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
	Cure();
	Cure(Cure const& asign);
	~Cure();

	Cure & operator=(Cure const & equal);

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);

	private:
};

#endif
