/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:28:10 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/27 16:21:42 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout<<"Cat default constructor called"<<std::endl;
    m_type = "Cat";
	m_brain = new Brain;
}

Cat::Cat(Cat const& asign)
{
    std::cout<<"Cat copy constructor called"<<std::endl;
	// Stockage d'une copie de l'attribut de brain de asign
	std::string	temp[100];
	for (int i = 0; i < 100; i++)
		temp[i] = asign.m_brain->getIdeas(i);
	// Allocation et affectation d'un brain independant
	m_brain = new Brain;
	for (int i = 0; i < 100; i++)
		m_brain->affectIdeas(temp[i], i);
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
	delete m_brain;
}

Cat &   Cat::operator=(Cat const & equal)
{
	std::cout<<"Copy Cat assignment operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_type = equal.m_type;
		// Liberation de l'ancien brain de mon objet
		delete m_brain;
		// Stockage d'une copie de l'attribut de brain de equal
		std::string	temp[100];
		for (int i = 0; i < 100; i++)
			temp[i] = equal.m_brain->getIdeas(i);
		// Allocation et affectation d'un brain independant
		m_brain = new Brain;
		for (int i = 0; i < 100; i++)
			m_brain->affectIdeas(temp[i], i);
	}
	return *this;
}

void    Cat::makeSound() const
{
    std::cout<<"Miaou Miaou..."<<std::endl;
}

void	Cat::affectIdeas(std::string const to_affect, int index)
{
	m_brain->affectIdeas(to_affect, index);
}

std::string	Cat::getIdeas(int index) const
{
	return m_brain->getIdeas(index);
}
