/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:56:05 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 13:46:23 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM__HPP
#define __PRESIDENTIALPARDONFORM__HPP

#include <string>
#include <iostream>
// #include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public :
	PresidentialPardonForm(std::string const name);
    PresidentialPardonForm(PresidentialPardonForm const& asign);
    virtual ~PresidentialPardonForm();

	PresidentialPardonForm & operator=(PresidentialPardonForm const& equal);

	std::string	getTarget() const;
	virtual void	performAction()const;

	private :

	std::string	m_target;

};

#endif
