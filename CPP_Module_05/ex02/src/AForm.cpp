/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:09:13 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/09 19:03:46 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/////////////// ATTENTION SEULEMENT MODIFIE LES FORM EN AFORM ///////////////////

AForm::AForm(std::string const name, int const grade_to_sign, int const grade_to_execute)
    :   m_grade_to_sign(valid_grades(grade_to_sign, grade_to_execute)),
        m_grade_to_execute(grade_to_execute),
        m_name(name),
        m_signed(false)
{
    std::cout<<"AForm "<<name<<" default constructor called"<<std::endl;
}

AForm::AForm(AForm const& asign)
    :   m_grade_to_sign(asign.getGradeToSign()),
        m_grade_to_execute(asign.getGradeToExecute()),
        m_name(asign.getName()),
        m_signed(asign.isSigned())
{
    std::cout<<"AForm copy constructor called"<<std::endl;
}

AForm::~AForm()
{
	std::cout<<"AForm destructor called"<<std::endl;
}

AForm& AForm::operator=(AForm const & equal)
{
	std::cout<<"AForm assignation operator called"<<std::endl;
	if (this != &equal)
	{
        this->m_signed = equal.isSigned();
	}
	return *this;
}

std::ostream &  operator<<(std::ostream & output, AForm const & input)
{
	output << "AForm's name : "<<input.getName();
    output << "\nForm's sign status : "<<input.isSigned();
    output << "\nForm's required grade to sign : "<<input.getGradeToSign();
    output << "\nForm's required grade to excecute : "<<input.getGradeToExecute();
	return output;
}

std::string AForm::getName() const
{
    return m_name;
}

bool    AForm::isSigned() const
{
    return m_signed;
}

int AForm::getGradeToExecute() const
{
    return m_grade_to_execute;
}

int AForm::getGradeToSign() const
{
    return m_grade_to_sign;
}

void    AForm::beSigned(Bureaucrat& bureaucrat)
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

AForm::GradeTooHighException::GradeTooHighException(std::string sentence) throw() : m_sentence(sentence)
{
	std::cout<<"GradeTooHighExcepetion constructor called"<<std::endl;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return m_sentence.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout<<"GradeTooHighExcepetion destructor called"<<std::endl;
}

AForm::GradeTooLowException::GradeTooLowException(std::string sentence) throw() : m_sentence(sentence)
{
	std::cout<<"GradeTooLowExcepetion constructor called"<<std::endl;
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return m_sentence.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout<<"GradeTooLowExcepetion destructor called"<<std::endl;
}


int	valid_grades(int const grade_to_sign, int const grade_to_execute)
{
    if (grade_to_sign < 1)
		throw AForm::GradeTooHighException("ERROR : The required grade to sign is too high.");
	else if (grade_to_sign > 150)
		throw AForm::GradeTooLowException("ERROR : The required grade to sign is too low.");
	else if (grade_to_execute < 1)
		throw AForm::GradeTooHighException("ERROR : The required grade to execute is too high.");
	else if (grade_to_execute > 150)
		throw AForm::GradeTooLowException("ERROR : The required grade to execute is too low.");
    return grade_to_sign;
}
