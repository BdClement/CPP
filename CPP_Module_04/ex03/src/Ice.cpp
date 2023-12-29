/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:42:36 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/29 19:36:08 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    // std::cout<<"Ice default constructor called"<<std::endl;
	m_type = "ice";
}

Ice::Ice(Ice const& asign)
{
    // std::cout<<"Ice copy constructor called"<<std::endl;
	this->m_type = asign.m_type;
}

Ice::~Ice()
{
    // std::cout<<"Ice destructor called"<<std::endl;
}

Ice &   Ice::operator=(Ice const & equal)
{
	// std::cout<<"Copy Ice assignment operator called"<<std::endl;
	(void)equal;
	return *this;
}

Ice*	Ice::clone() const
{
		return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}
