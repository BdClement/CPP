/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:28:55 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/27 21:06:00 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout<<"AMateria default constructor called"<<std::endl;
}

AMateria::AMateria(std::string const & type) : m_type(type)
{
	std::cout<<"AMateria default constructor called"<<std::endl;
}

AMateria::AMateria(AMateria const& asign)
{
    std::cout<<"AMateria copy constructor called"<<std::endl;
	*this = asign;
}

AMateria::~AMateria()
{
    std::cout<<"AMateria destructor called"<<std::endl;
}

AMateria &   AMateria::operator=(AMateria const & equal)
{
	std::cout<<"Copy AMateria assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_type = equal.m_type;
	}
	return *this;
}

std::string const & AMateria::getType() const
{
	return m_type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}
