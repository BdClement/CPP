/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:19 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/27 21:23:01 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout<<"MateriaSource default constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		m_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& asign)
{
    std::cout<<"MateriaSource copy constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		this->m_materia[i] = asign.clone(i);
}

MateriaSource::~MateriaSource()
{
    std::cout<<"MateriaSource destructor called"<<std::endl;
	// delete m_inventory ?
}

MateriaSource &   MateriaSource::operator=(MateriaSource const & equal)
{
	std::cout<<"Copy MateriaSource assignment operator called"<<std::endl;
	if (this != &equal)
	{
		// Liberation des anciennes materia
		for (int i = 0; i < 4; i++)
		{
			if (m_materia[i] != NULL)
				delete m_materia[i];
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
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (m_materia[i] == NULL)
			m_materia[i] = m;
	}
	// Copie la AMateria passe en parametre t la stocke en mémoire afin de la cloner
	// plus tard
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == m_materia[i]->getType())
			return m_materia[i]->clone();
	}
	return 0;
	// Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment
	// par la MateriaSource et dont le type est le même que celui passé en paramètre.
	// Retourne 0 si le type est inconnu
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
