/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:28:10 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:18:57 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout<<"Cat default constructor called"<<std::endl;
    m_type = "Cat";
}

// Cat::Cat(std::string type) : Animal(type)
// {
//     std::cout<<"Cat constructor called"<<std::endl;
// }

Cat::Cat(Cat const& asign)
{
    std::cout<<"Cat copy constructor called"<<std::endl;
    *this = asign;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
}

Cat &   Cat::operator=(Cat const & equal)
{
	std::cout<<"Copy Cat assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_type = equal.m_type;
	}
	return *this;
}

void    Cat::makeSound() const
{
    std::cout<<"Miaou Miaou..."<<std::endl;
}
