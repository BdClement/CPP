/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:49:34 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 14:45:51 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM__HPP
#define __ROBOTOMYREQUESTFORM__HPP

#include <string>
#include <iostream>
// #include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public :
	RobotomyRequestForm(std::string const name);
    RobotomyRequestForm(RobotomyRequestForm const& asign);
    virtual ~RobotomyRequestForm();

	RobotomyRequestForm & operator=(RobotomyRequestForm const& equal);

	std::string	getTarget() const;
	virtual void	performAction() const;

	private :

	std::string	m_target;

};

#endif
