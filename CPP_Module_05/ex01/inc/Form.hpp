/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:09:17 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/15 20:14:07 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM__HPP
#define __FORM__HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

    Form(std::string const name, int const grade_to_sign, int const grade_to_execute);
    Form(Form const& asign);
    ~Form();

	Form & operator=(Form const& equal);

    std::string getName() const;
    bool  isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void    beSigned(Bureaucrat& bureaucrat);

    private:
    int const           m_grade_to_sign;
    int const           m_grade_to_execute;
    std::string const   m_name;
    bool                m_signed;

};

int	valid_grades(int const grade_to_sign, int const grade_to_execute);
std::ostream &  operator<<(std::ostream & output, Form const & input);

#endif
