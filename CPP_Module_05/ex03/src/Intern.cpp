/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:09:24 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 20:26:27 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	// std::cout<<"Intern default constructor called"<<std::endl;
	m_forms[0] = "shrubbery creation";
	m_forms[1] = "robotomy request";
	m_forms[2] = "presidential pardon";
	m_function_tab[0] = &CreateShrubberyCreationForm;
	m_function_tab[1] = &CreateRobotomyRequestForm;
	m_function_tab[2] = &CreatePresidentialPardonForm;
}

Intern::Intern(Intern const& asign)
{
	// std::cout<<"Intern copy constructor called"<<std::endl;
	m_forms[0] = "shrubbery creation";
	m_forms[1] = "robotomy request";
	m_forms[2] = "presidential pardon";
	m_function_tab[0] = &CreateShrubberyCreationForm;
	m_function_tab[1] = &CreateRobotomyRequestForm;
	m_function_tab[2] = &CreatePresidentialPardonForm;
	*this = asign;
}

Intern::~Intern()
{
	// std::cout<<"Intern destructor called"<<std::endl;
}

Intern& Intern::operator=(Intern const & equal)
{
	// std::cout<<"Intern assignation operator called"<<std::endl;
	(void)equal;
	return *this;
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	for	(int i = 0; i < 3; i++)
	{
		if (formName == m_forms[i])
			return m_function_tab[i](formTarget);
	}
	std::cout<<formName<<" form doesn't exist"<<std::endl;
	return NULL;
}

AForm*	CreateShrubberyCreationForm(std::string target)
{
	AForm *form = new ShrubberyCreationForm(target);
	std::cout<<"Intern creates "<<form->getName()<<std::endl;
	return form;
}

AForm*	CreateRobotomyRequestForm(std::string target)
{
	AForm *form = new RobotomyRequestForm(target);
	std::cout<<"Intern creates "<<form->getName()<<std::endl;
	return form;
}

AForm*	CreatePresidentialPardonForm(std::string target)
{
	AForm *form = new PresidentialPardonForm(target);
	std::cout<<"Intern creates "<<form->getName()<<std::endl;
	return form;
}

