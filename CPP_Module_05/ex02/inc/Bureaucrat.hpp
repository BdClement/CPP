/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:21:51 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/09 17:48:02 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT__HPP
#define __BUREAUCRAT__HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:

	class GradeTooHighException : public std::exception
	{
		public:
		GradeTooHighException(std::string sentence) throw();
		virtual const char* what() const throw();
		virtual ~GradeTooHighException() throw();
		private:
		std::string m_sentence;
	};
	class GradeTooLowException : public std::exception
	{
		public:
		GradeTooLowException(std::string sentence) throw();
		virtual const char* what() const throw();
		virtual ~GradeTooLowException() throw();
		private:
		std::string m_sentence;
	};
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const& asign);
	~Bureaucrat();

	Bureaucrat & operator=(Bureaucrat const& equal);
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(Form& form);

	private:
	int					m_grade;
	std::string const	m_name;
};

// Autre option possible, include valid_grade a la class en tant que methode static
// Pour rappel, un methode static dans une classe peut etre appelee sans instance de cette meme classe
int	valid_grade(int grade);
std::ostream &  operator<<(std::ostream & output, Bureaucrat const & input);

#endif
