/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:09:13 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/15 20:15:29 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int const grade_to_sign, int const grade_to_execute)
    :   m_grade_to_sign(valid_grades(grade_to_sign, grade_to_execute)),
        m_grade_to_execute(grade_to_execute),
        m_name(name),
        m_signed(false)
{
    std::cout<<"Form "<<name<<" default constructor called"<<std::endl;
}

Form::Form(Form const& asign)
    :   m_grade_to_sign(asign.getGradeToSign()),
        m_grade_to_execute(asign.getGradeToExecute()),
        m_name(asign.getName()),
        m_signed(asign.isSigned())
{
    std::cout<<"Form copy constructor called"<<std::endl;
}

Form::~Form()
{
	std::cout<<"Form destructor called"<<std::endl;
}

Form& Form::operator=(Form const & equal)
{
	std::cout<<"Form assignation operator called"<<std::endl;
	if (this != &equal)
	{
        this->m_signed = equal.isSigned();
	}
	return *this;
}

std::ostream &  operator<<(std::ostream & output, Form const & input)
{
	output << "Form's name : "<<input.getName();
    output << "\nForm's sign status : "<<input.isSigned();
    output << "\nForm's required grade to sign : "<<input.getGradeToSign();
    output << "\nForm's required grade to excecute : "<<input.getGradeToExecute();
	return output;
}

std::string Form::getName() const
{
    return m_name;
}

bool    Form::isSigned() const
{
    return m_signed;
}

int Form::getGradeToExecute() const
{
    return m_grade_to_execute;
}

int Form::getGradeToSign() const
{
    return m_grade_to_sign;
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    try
    {
        if (bureaucrat.getGrade() > this->getGradeToSign())
            throw GradeTooLowException("ERROR : Impossible to sign");
        m_signed = true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Form::GradeTooHighException::GradeTooHighException(std::string sentence) throw() : m_sentence(sentence)
{
	// std::cout<<"GradeTooHighExcepetion constructor called"<<std::endl;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return m_sentence.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	// std::cout<<"GradeTooHighExcepetion destructor called"<<std::endl;
}

Form::GradeTooLowException::GradeTooLowException(std::string sentence) throw() : m_sentence(sentence)
{
	// std::cout<<"GradeTooLowExcepetion constructor called"<<std::endl;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return m_sentence.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	// std::cout<<"GradeTooLowExcepetion destructor called"<<std::endl;
}


int	valid_grades(int const grade_to_sign, int const grade_to_execute)
{
    if (grade_to_sign < 1)
		throw Form::GradeTooHighException("ERROR : The required grade to sign is too high.");
	else if (grade_to_sign > 150)
		throw Form::GradeTooLowException("ERROR : The required grade to sign is too low.");
	else if (grade_to_execute < 1)
		throw Form::GradeTooHighException("ERROR : The required grade to execute is too high.");
	else if (grade_to_execute > 150)
		throw Form::GradeTooLowException("ERROR : The required grade to execute is too low.");
    return grade_to_sign;
}
