/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:06:01 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/27 16:21:20 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain()
{
    std::cout<<"Brain default constructor called"<<std::endl;
}

Brain::Brain(Brain const& asign)
{
    std::cout<<"Brain copy constructor called"<<std::endl;
    *this = asign;
}

Brain::~Brain()
{
    std::cout<<"Brain destructor called"<<std::endl;
}

Brain &   Brain::operator=(Brain const & equal)
{
	std::cout<<"Copy Brain assignment operator called"<<std::endl;
	if (this != &equal)
	{
		for (int i = 0; i < 100; i++)
			this->affectIdeas(equal.getIdeas(i), i);
	}
	return *this;
}

std::string	Brain::getIdeas(int index) const
{
	return m_ideas[index];
}

void		Brain::affectIdeas(std::string const to_affect, int index)
{
	m_ideas[index] = to_affect;
}
