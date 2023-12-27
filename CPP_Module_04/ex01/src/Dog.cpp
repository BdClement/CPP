/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:23:33 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/27 16:21:54 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout<<"Dog default constructor called"<<std::endl;
    m_type = "Dog";
	m_brain = new Brain;
}

Dog::Dog(Dog const& asign)
{
    std::cout<<"Dog copy constructor called"<<std::endl;
	// Stockage d'une copie de l'attribut de brain de asign
	std::string	temp[100];
	for (int i = 0; i < 100; i++)
		temp[i] = asign.m_brain->getIdeas(i);
	// Allocation et affectation d'un brain independant
	m_brain = new Brain;
	for (int i = 0; i < 100; i++)
		m_brain->affectIdeas(temp[i], i);
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
	delete m_brain;
}

Dog &   Dog::operator=(Dog const & equal)
{
	std::cout<<"Copy Dog assignment operator called"<<std::endl;
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

void    Dog::makeSound() const
{
    std::cout<<"Wouaf Wouaf..."<<std::endl;
}

void	Dog::affectIdeas(std::string const to_affect, int index)
{
	m_brain->affectIdeas(to_affect, index);
}

std::string	Dog::getIdeas(int index) const
{
	return m_brain->getIdeas(index);
}
