/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:59:12 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/28 17:57:29 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE__HPP
#define __MATERIASOURCE__HPP

#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	public:
	MateriaSource();
	MateriaSource(MateriaSource const& asign);
	virtual ~MateriaSource();

	MateriaSource & operator=(MateriaSource const & equal);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
	AMateria*		clone(int idx) const;
	bool		materia_tab_is_full();

	private:
	AMateria	*m_materia[4];
};

#endif
