/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:57:57 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/15 17:51:52 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::cout<<"\n**** INITIALISATIONS ****"<<std::endl;
	try
	{
		std::cout<<"\nForms :"<<std::endl;
		AForm	*form1 = new PresidentialPardonForm("target1");
		AForm	*form2 = new RobotomyRequestForm("target2");
		AForm	*form3 = new ShrubberyCreationForm("target3");
		std::cout<<"\nBureaucrats :"<<std::endl;
		Bureaucrat	Pierre("Pierre", 149);
		Bureaucrat	Jaques("Jaques", 2);
		std::cout<<"\n**** TEST DES FONCTIONS DEMANDEES PAR LE SUJET ****"<<std::endl;
		std::cout<<"\nTentative d'executeForm avant d'avoir ete signe: \n"<<std::endl;
		Pierre.executeForm(*form1);
		Pierre.executeForm(*form2);
		Jaques.executeForm(*form3);
		std::cout<<"\nSignatures des 3 form :\n"<<std::endl;
		Jaques.signForm(*form1);
		Jaques.signForm(*form2);
		Jaques.signForm(*form3);
		std::cout<<"\nTentative d'executeForm apres d'avoir ete signe: \n"<<std::endl;
		std::cout<<"Pierre"<<std::endl;
		Pierre.executeForm(*form1);
		Pierre.executeForm(*form2);
		Pierre.executeForm(*form3);
		std::cout<<"\nJaques"<<std::endl;
		Jaques.executeForm(*form1);
		Jaques.executeForm(*form2);
		Jaques.executeForm(*form2);
		Jaques.executeForm(*form3);
		Jaques.executeForm(*form3);
		std::cout<<"\nDestructor"<<std::endl;
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
