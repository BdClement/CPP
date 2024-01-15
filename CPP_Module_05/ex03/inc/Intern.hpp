/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:05:37 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 20:01:43 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN__HPP
#define __INTERN__HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Intern
{
	public:
	Intern();
	Intern(Intern const& asign);
	~Intern();

	Intern & operator=(Intern const& equal);

	AForm*	makeForm(std::string formName, std::string formTarget);
	private:
	std::string	m_forms[3];
	AForm*	(*m_function_tab[3])(std::string target);
};

AForm*	CreatePresidentialPardonForm(std::string target);
AForm*	CreateRobotomyRequestForm(std::string target);
AForm*	CreateShrubberyCreationForm(std::string target);

#endif
