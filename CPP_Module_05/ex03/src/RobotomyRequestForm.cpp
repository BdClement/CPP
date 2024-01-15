/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:50:47 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 19:49:18 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45), m_target(target)
{
	// std::cout<<"RobotomyRequestForm "<<this->getName()<<" default constructor called"<<std::endl;
}

// A TESTER ??
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& asign)
	: AForm(asign.getName(), asign.getGradeToSign(), asign.getGradeToExecute()), m_target(asign.getTarget())
{
	// std::cout<<"RobotomyRequestForm copy constructor called"<<std::endl;
	// *this = asign;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout<<"RobotomyRequestForm destructor called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & equal)
{
	// std::cout<<"RobotomyRequestForm assignation operator called"<<std::endl;
	if (this != &equal)
	{
        this->changeSignature(equal.isSigned());
		this->m_target = equal.getTarget();
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return m_target;
}

void	RobotomyRequestForm::performAction()const
{
	static int	i = 0;
	std::cout<<"Drilling noises @#! ..."<<std::endl;
	if (i++ % 2 == 0)
	std::cout<<this->getTarget()<<" has been robotomized successfully"<<std::endl;
	else
	std::cout<<"Robotomy failed"<<std::endl;
}
