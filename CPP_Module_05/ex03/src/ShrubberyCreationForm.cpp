/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:27 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 19:49:37 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137), m_target(target)
{
	// std::cout<<"ShrubberyCreationForm "<<this->getName()<<" default constructor called"<<std::endl;
}

// A TESTER ??
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& asign)
	: AForm(asign.getName(), asign.getGradeToSign(), asign.getGradeToExecute()), m_target(asign.getTarget())
{
	// std::cout<<"ShrubberyCreationForm copy constructor called"<<std::endl;
	// *this = asign;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout<<"ShrubberyCreationForm destructor called"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & equal)
{
	// std::cout<<"ShrubberyCreationForm assignation operator called"<<std::endl;
	if (this != &equal)
	{
        this->changeSignature(equal.isSigned());
		this->m_target = equal.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return m_target;
}

void	ShrubberyCreationForm::performAction()const
{
	std::string	filename(this->getTarget() + "_shrubbery");
	std::ofstream	outfile(filename.c_str() , std::ofstream::out | std::ios::app);
	if (outfile.is_open())
	{
		outfile << "    /\\\n";
        outfile << "   /  \\\n";
        outfile << "  /    \\\n";
        outfile << " /      \\\n";
        outfile << "/________\\\n";
        outfile << "   ||||\n";
        outfile << "   ||||\n";
		outfile.close();
	}
	else
		std::cerr<<"ERROR : File couldn't be open"<<std::endl;
}

