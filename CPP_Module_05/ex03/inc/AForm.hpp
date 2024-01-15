/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:09:17 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/15 14:46:37 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM__HPP
#define __AFORM__HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
	class FormNotSigned : public std::exception
	{
		public:
		FormNotSigned(std::string sentence) throw();
		virtual const char* what() const throw();
		virtual ~FormNotSigned() throw();
		private:
		std::string m_sentence;
	};

    AForm(std::string const name, int const grade_to_sign, int const grade_to_execute);
    AForm(AForm const& asign);
    virtual ~AForm();

	AForm & operator=(AForm const& equal);

    std::string getName() const;
    bool  isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void    beSigned(Bureaucrat& bureaucrat);
	void	changeSignature(bool newSignature);
	void	execute(Bureaucrat const & executor) const;
	virtual void	performAction() const = 0;

    private:
    int const           m_grade_to_sign;
    int const           m_grade_to_execute;
    std::string const   m_name;
    bool                m_signed;

};

int	valid_grades(int const grade_to_sign, int const grade_to_execute);
std::ostream &  operator<<(std::ostream & output, AForm const & input);

#endif
