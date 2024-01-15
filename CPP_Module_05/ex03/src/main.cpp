/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:57:57 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 20:03:53 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* rrf2;
	AForm* rrf3;
	AForm* rrf4;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf2 = someRandomIntern.makeForm("shrubbery creation", "Bender");
	rrf3 = someRandomIntern.makeForm("presidential pardon", "Bender");
	rrf4 = someRandomIntern.makeForm("invalid", "Bender");
	delete rrf;
	delete rrf2;
	delete rrf3;
	return 0;
}
