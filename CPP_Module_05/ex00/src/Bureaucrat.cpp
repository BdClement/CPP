/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:30:45 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/08 19:56:44 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : m_grade((valid_grade(grade))), m_name(name)
{
		std::cout<<"Bureaucrat "<<name<<" default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& asign) : m_grade(asign.getGrade()), m_name(asign.getName())
{
	std::cout<<"Bureaucrat copy constructor called"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat destructor called"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & equal)
{
	std::cout<<"Bureaucrat assignation operator called"<<std::endl;
	if (this != &equal)
	{
		this->m_grade = equal.getGrade();
		// this->m_name = equal.getName();// Pb impossible de copier name car const
	}
	return *this;
}

std::ostream &  operator<<(std::ostream & output, Bureaucrat const & input)
{
	output << input.getName()<<", bureaucrat grade "<<input.getGrade()<<".";
	return output;
}

std::string Bureaucrat::getName() const
{
	return m_name;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (m_grade == 1)
			throw GradeTooHighException("Bureaucrat is already first graded");
		m_grade--;
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (m_grade == 150)
			throw GradeTooLowException("Bureaucrat is last graded. He can't be lower graded");
		m_grade++;
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string sentence) throw() : m_sentence(sentence)
{
	std::cout<<"GradeTooHighExcepetion constructor called"<<std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return m_sentence.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	// (void);
	std::cout<<"GradeTooHighExcepetion destructor called"<<std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string sentence) throw() : m_sentence(sentence)
{
	std::cout<<"GradeTooLowExcepetion constructor called"<<std::endl;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return m_sentence.c_str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout<<"GradeTooLowExcepetion destructor called"<<std::endl;
}

int	valid_grade(int grade)
{
	if (grade < 1)
			throw Bureaucrat::GradeTooHighException("ERROR : The grade is too high.");
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException("ERROR : The grade is too low.");
		return grade;
}
