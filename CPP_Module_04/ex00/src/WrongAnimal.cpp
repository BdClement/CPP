/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:10:19 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:19:03 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout<<"WrongAnimal default constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& asign)
{
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
    *this = asign;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor called"<<std::endl;
}

WrongAnimal &   WrongAnimal::operator=(WrongAnimal const & equal)
{
	std::cout<<"Copy WrongAnimal assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_type = equal.m_type;
	}
	return *this;
}

const std::string& WrongAnimal::getType() const
{
    return m_type;
}

std::ostream &  operator<<(std::ostream & output, WrongAnimal const & input)
{
    output << input.getType();
    return output;
}

void    WrongAnimal::makeSound() const 
{
    std::cout<<"WrongAnimal sound..."<<std::endl;
}
