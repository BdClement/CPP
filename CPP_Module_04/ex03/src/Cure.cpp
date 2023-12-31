/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:52:27 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/29 19:35:54 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    // std::cout<<"Cure default constructor called"<<std::endl;
	m_type = "cure";
}

Cure::Cure(Cure const& asign)
{
    // std::cout<<"Cure copy constructor called"<<std::endl;
	this->m_type = asign.m_type;
}

Cure::~Cure()
{
    // std::cout<<"Cure destructor called"<<std::endl;
}

Cure &   Cure::operator=(Cure const & equal)
{
	// std::cout<<"Copy Cure assignment operator called"<<std::endl;
	(void)equal;
	return *this;
}

Cure*	Cure::clone() const
{
		return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}
