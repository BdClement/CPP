/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:30:45 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/08 15:34:45 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade)
{

}

Bureaucrat::Bureaucrat(Bureaucrat const& asign)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & equal)
{

	return *this;
}

std::ostream &  operator<<(std::ostream & output, Bureaucrat const & input)
{
	output << input.getName()<<", bureaucrate grade "<<input.getGrade()<<".";
	return output;
}

std::name Bureaucrat::getName() const
{
	return m_name;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

void Bureaucrat::incrementGrade()
{
	m_grade--;
}

void Bureaucrat::decrementGrade()
{
	m_grade++;
}
