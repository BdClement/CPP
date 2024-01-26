/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:13:31 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/26 13:20:41 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// // Test du sujet
// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int	main()
{
	std::cout<<"*** Test de la forme canonique de la class Span ***\n"<<std::endl;
	{
		Span	test1(5);
		for (int i = 0; i < 4; i++)
			test1.addNumber(i);
		std::cout<<"Creation d'un objet span test1 : ";
		test1.print();
		Span	test2(test1);
		std::cout<<"\nCreation d'un objet span test2 par constructeur de copie : ";
		test2.print();
		Span	test3(10);
		test3 = test2;
		std::cout<<"\nCreation d'un objet span test3 par operateur d'assignation : ";
		test3.print();
		test1.addNumber(10);
		std::cout<<"\nAjout du nombre 10 a test1.\nTest1 = ";
		test1.print();
		std::cout<<"\nTest2 = ";
		test2.print();
		std::cout<<"\nTest3 = ";
		test3.print();
		std::cout<<"\nTentaive d'ajouter 2 nombres a test3, qui a ete construit avec une limite de 10 nombres max mais a ete assigne a test2 qui lui a une limite a 5"<<std::endl;
		test3.addNumber(20);
		std::cout<<"Test3 apres le premier ajout = ";
		test3.print();
		std::cout<<std::endl;
		test3.addNumber(200);
	}
	{
		std::cout<<"\n\n*** Test des fonction longestSpan() et shortestSpan() ***\n"<<std::endl;
		std::cout<<"Creation d'un objet span test1, pouvant accueillir 100 000 nombres max"<<std::endl;
		Span	test1(100000);
		try
		{
			std::cout<<"Tentavive de trouver longestSpan et shortestSpan sur test1 vide"<<std::endl;
			test1.longestSpan();
			test1.shortestSpan();
		}
		catch (const std::exception&)
		{
			std::cout<<"Exception catched : Span object must have at least 2 elements to find a span"<<std::endl;
		}
		std::cout<<"Remplissage avec les nombres de -50 000 a 49 999"<<std::endl;
		for (int i = -50000; i < 50000; i++)
			test1.addNumber(i);
		std::cout<<"longestSpan = "<<test1.longestSpan()<<std::endl;
		std::cout<<"shortestSpan = "<<test1.shortestSpan()<<std::endl;
		std::cout<<"\n\n*** Test de la fonction addNumbers qui permet d'ajouter plusieurs nombre a la Span ***\n"<<std::endl;
		Span test2(10);
		std::cout<<"Creation d'un objet span test2 vide pouvant accueillir 10 nombres maximum"<<std::endl;
		test2.addNumbers(test1.getBegin(), (test1.getBegin() + 10));
		std::cout<<"Remplissage de test2 avec les 10 premiers nombres de test1\nTest2 : ";
		test2.print();
		std::cout<<"\nTentative de remplissage de test2 avec les 10 nombres suivants de test1\n";
		test2.addNumbers(test1.getBegin() + 10, test1.getBegin() + 20);
		std::cout<<"Test2 : ";
		test2.print();
		std::cout<<"\nlongestSpan test2 = "<<test2.longestSpan()<<std::endl;
		std::cout<<"shortestSpan  test2 = "<<test2.shortestSpan()<<std::endl;
	}
	return 0;
}
