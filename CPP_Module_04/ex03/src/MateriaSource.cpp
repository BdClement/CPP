/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:19 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/29 22:47:27 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

AMateria* historic[1000] = {};

MateriaSource::MateriaSource()
{
    std::cout<<"MateriaSource default constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		m_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& asign)
{
    // std::cout<<"MateriaSource copy constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		this->m_materia[i] = asign.clone(i);
}

MateriaSource::~MateriaSource()
{
    // std::cout<<"MateriaSource destructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (m_materia[i] != NULL)
		{
			delete m_materia[i];
			m_materia[i] = NULL;
		}
	}
	free_historic();
}

MateriaSource &   MateriaSource::operator=(MateriaSource const & equal)
{
	// std::cout<<"Copy MateriaSource assignment operator called"<<std::endl;
	if (this != &equal)
	{
		// Liberation des anciennes materia
		for (int i = 0; i < 4; i++)
		{
			if (m_materia[i] != NULL)
			{
				delete m_materia[i];
				m_materia[i] = NULL;
			}
		}
		// Affectation de mon inventaire
		for (int i = 0; i < 4; i++)
			this->m_materia[i] = equal.clone(i);
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (materia_tab_is_full())
	{
		std::cout<<"Les materias sont trop nombreuses"<< std::endl;
		add_to_historic(m);
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (m_materia[i] == NULL)
		{
			m_materia[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == m_materia[i]->getType())
		{
			AMateria *tmp = m_materia[i]->clone();
			add_to_historic(tmp);
			return tmp;
		}
	}
	std::cout<<"La materia de type "<<type<<" n'a pas pu etre créer"<<std::endl;
	return 0;
}

AMateria*	MateriaSource::clone(int idx) const
{
	return m_materia[idx]->clone();
}

bool	MateriaSource::materia_tab_is_full()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_materia[i] == NULL)
			return false;
	}
	return true;
}

void	MateriaSource::add_to_historic(AMateria* m)
{
	for (int i = 0; i < 1000; i++)
	{
		if (historic[i] == NULL)
		{
			historic[i] = m;
			return ;
		}
	}
	std::cout<<"Warning : Historic is not big enough !"<<std::endl;
}

void	MateriaSource::free_historic()
{
	for (int i = 0; i < 1000; i++)
	{
		if (historic[i] != NULL)
		{
			delete historic[i];
			historic[i] = NULL;
		}
		else
			return ;
	}
}
