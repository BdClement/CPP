/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:23:33 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:18:59 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout<<"Dog default constructor called"<<std::endl;
    m_type = "Dog";
}

// Dog(std::string type) : Animal(type)
// {
//     std::cout<<"Dog constructor called"<<std::endl;
//     m_type = "Dog";
// }

Dog::Dog(Dog const& asign)
{
    std::cout<<"Dog copy constructor called"<<std::endl;
    *this = asign;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
}

Dog &   Dog::operator=(Dog const & equal)
{
	std::cout<<"Copy Dog assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_type = equal.m_type;
	}
	return *this;
}

void    Dog::makeSound() const 
{
    std::cout<<"Wouaf Wouaf..."<<std::endl;
}
