/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:12:54 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:29:57 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout<<"WrongCat default constructor called"<<std::endl;
    m_type = "WrongCat";
}

// WrongCat::WrongCat(std::string type) : WrongAnimal(type)
// {
//     std::cout<<"WrongCat constructor called"<<std::endl;
// }

WrongCat::WrongCat(WrongCat const& asign)
{
    std::cout<<"WrongCat copy constructor called"<<std::endl;
    *this = asign;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor called"<<std::endl;
}

WrongCat &   WrongCat::operator=(WrongCat const & equal)
{
	std::cout<<"Copy WrongCat assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_type = equal.m_type;
	}
	return *this;
}

void    WrongCat::makeSound() const
{
    std::cout<<"Wrong Miaou Miaou..."<<std::endl;
}
