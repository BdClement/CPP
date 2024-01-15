/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:12:43 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 19:49:00 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5), m_target(target)
{
	// std::cout<<"PresidentialPardonForm "<<this->getName()<<" default constructor called"<<std::endl;
}

// A TESTER ??
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& asign)
	: AForm(asign.getName(), asign.getGradeToSign(), asign.getGradeToExecute()), m_target(asign.getTarget())
{
	// std::cout<<"PresidentialPardonForm copy constructor called"<<std::endl;
	// *this = asign;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout<<"PresidentialPardonForm destructor called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & equal)
{
	// std::cout<<"PresidentialPardonForm assignation operator called"<<std::endl;
	if (this != &equal)
	{
        this->changeSignature(equal.isSigned());
		this->m_target = equal.getTarget();
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
    return m_target;
}

void	PresidentialPardonForm::performAction() const
{
	std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}
