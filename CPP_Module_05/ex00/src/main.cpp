/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:57:57 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/08 20:02:34 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout<<"**** EXEMPLES D'INITIALISATIONS INVALIDES ****"<<std::endl<<std::endl;
	try
	{
		Bureaucrat	Pierre("Pierre", 151);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	Paul("Paul", 0);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<"\n**** INITIALISATIONS VALIDES ****"<<std::endl;
	std::cout<<"TEST DU CONSTRUCTEUR DE COPIE ET DE LA SURCHARGE D'OPERATEUR D'ASSIGNATION ="<<std::endl<<std::endl;
	try
	{
		Bureaucrat	Jaques("Jaques", 1);
		Bureaucrat	Pierre(Jaques);
		Bureaucrat	Paul("Paul", 5);
		Paul = Pierre;
		std::cout<<"\nTEST DE L'OPERATEUR << AVEC getName() et getGrade():\n"<<std::endl;
		std::cout<<Jaques<<std::endl;
		std::cout<<Pierre<<std::endl;
		std::cout<<Paul<<std::endl<<std::endl;
		std::cout<<"TEST DE incrementGrade()"<<std::endl;
		Jaques.incrementGrade();
		std::cout<< "\nJAQUES EST MIS AU PLUS PETIT GRADE PUIS TEST DE decrementGrade()"<<std::endl;
		for (int i = 1; i < 151; i++)
			Jaques.decrementGrade();
		std::cout<<"\nTEST DE LA BONNE APPLICATION DE LA LIMITE DE GRADE"<<std::endl;
		std::cout<<Jaques<<std::endl<<std::endl;
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
