/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:57:57 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/19 11:55:39 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout<<"**** EXEMPLES D'INITIALISATIONS INVALIDES ****"<<std::endl<<std::endl;
	try
	{
		Form	form1("form1", 0, 12);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	form2("form2", 5, 151);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<"\n**** INITIALISATIONS VALIDES ****"<<std::endl;
	std::cout<<"TEST DU CONSTRUCTEUR DE COPIE ET DE LA SURCHARGE D'OPERATEUR D'ASSIGNATION ="<<std::endl<<std::endl;
	try
	{
		Form	form3("form3", 25, 50);
		Form	form4(form3);
		Form	form5("form5", 140, 140);
		form5 = form4;
		Bureaucrat	Pierre("Pierre", 141);
		Bureaucrat	Jaques("Jaques", 25);
		std::cout<<"\nTEST DE L'OPERATEUR << AVEC LES 4 FONCTION GETTERS:\n"<<std::endl;
		std::cout<<form3<<"\n"<<std::endl;
		std::cout<<form4<<"\n"<<std::endl;
		std::cout<<form5<<"\n"<<std::endl<<std::endl;
		
		std::cout<<"TEST DE signForm()"<<std::endl;
		std::cout<<"Jaques grade 25 tente de signer form3 qui necessite au moins un grade 25"<<std::endl;
		Jaques.signForm(form3);
		std::cout<<form3<<"\n"<<std::endl;
		std::cout<<"On retire un grade a Jaques qui tente de signer form4 qui necessite au moins 25 egalement"<<std::endl;
		Jaques.decrementGrade();
		Jaques.signForm(form4);
		std::cout<<form4<<"\n"<<std::endl;
		std::cout<<"Pierre grade 141 tente de signer form5 qui necessite au moins le grade 140"<<std::endl;
		Pierre.signForm(form5);
		std::cout<<form5<<"\n"<<std::endl;
		std::cout<<"Hop, Pierre gagne un grade et tente desormais de signer form5"<<std::endl;
		Pierre.incrementGrade();
		Pierre.signForm(form5);
		std::cout<<form5<<"\n"<<std::endl;
		std::cout<<"Pierre tente de resigner form5"<<std::endl;
		Pierre.signForm(form5);
		std::cout<<form5<<"\n"<<std::endl;
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
