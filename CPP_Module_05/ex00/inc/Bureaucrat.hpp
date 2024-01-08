/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:21:51 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/08 15:39:41 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT__HPP
#define __BUREAUCRAT__HPP

#include <string>
#include <iostream>
#include <exception>

class GradeTooHighException
{

};

class GradeTooLowException
{

};



class Bureaucrat
{
	public:
	Bureaucrat(int grade);
	Bureaucrat(Bureaucrat const& asign);
	~Bureaucrat();

	Bureaucrat & operator=(Bureaucrat const& equal);
	std::name	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

	private:
	std::string const	m_name;
	int					m_grade;
};

std::ostream &  operator<<(std::ostream & output, Bureaucrat const & input);

#endif
