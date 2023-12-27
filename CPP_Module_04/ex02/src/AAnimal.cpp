/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:07:28 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/27 16:53:37 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout<<"AAnimal default constructor called"<<std::endl;
}

AAnimal::AAnimal(std::string type) : m_type(type)
{
    std::cout<<"AAnimal constructor called"<<std::endl;
}

AAnimal::AAnimal(AAnimal const& asign)
{
    std::cout<<"AAnimal copy constructor called"<<std::endl;
    *this = asign;
}

AAnimal::~AAnimal()
{
    std::cout<<"AAnimal destructor called"<<std::endl;
}

AAnimal &   AAnimal::operator=(AAnimal const & equal)
{
	std::cout<<"Copy AAnimal assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_type = equal.m_type;
	}
	return *this;
}

const std::string& AAnimal::getType() const
{
    return m_type;
}

std::ostream &  operator<<(std::ostream & output, AAnimal const & input)
{
    output << input.getType();
    return output;
}

// void    AAnimal::makeSound() const
// {
//     std::cout<<"AAnimal sound..."<<std::endl;
// }
