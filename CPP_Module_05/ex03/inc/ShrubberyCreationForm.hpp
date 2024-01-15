/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:44:22 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 13:46:18 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM__HPP
#define __SHRUBBERYCREATIONFORM__HPP

#include <string>
#include <iostream>
// #include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public :
	ShrubberyCreationForm(std::string const name);
    ShrubberyCreationForm(ShrubberyCreationForm const& asign);
    virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const& equal);

	std::string	getTarget() const;
	virtual void	performAction()const;

	private :

	std::string	m_target;

};

#endif
