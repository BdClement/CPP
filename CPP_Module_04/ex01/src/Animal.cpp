/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:07:28 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/27 13:06:11 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout<<"Animal default constructor called"<<std::endl;
}

Animal::Animal(std::string type) : m_type(type)
{
    std::cout<<"Animal constructor called"<<std::endl;
}

Animal::Animal(Animal const& asign)
{
    std::cout<<"Animal copy constructor called"<<std::endl;
    *this = asign;
}

Animal::~Animal()
{
    std::cout<<"Animal destructor called"<<std::endl;
}

Animal &   Animal::operator=(Animal const & equal)
{
	std::cout<<"Copy Animal assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_type = equal.m_type;
	}
	return *this;
}

const std::string& Animal::getType() const
{
    return m_type;
}

std::ostream &  operator<<(std::ostream & output, Animal const & input)
{
    output << input.getType();
    return output;
}

void    Animal::makeSound() const
{
    std::cout<<"Animal sound..."<<std::endl;
}
