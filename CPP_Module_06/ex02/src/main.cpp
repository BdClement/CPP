/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:54:25 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/18 19:54:30 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <string>
#include <iostream>

int	main()
{
	// Test de la fonction generate
	Base	*test1 = generate();
	Base	*test2 = generate();
	Base	*test3 = generate();
	// (void)test1;
	// (void)test2;
	// (void)test3;

	// Test de la fonction identify avec pointeur 
	// std::cout<<"test1 est un objet de type : ";
	identify(test1);
	// std::cout<<"\ntest2 est un objet de type : ";
	identify(test2);
	// std::cout<<"\ntest3 est un objet de type : ";
	identify(test3);

	// Test de la fonction identify avec adresse
	// std::cout<<"test1 est un objet de type : ";
	identify(&(*test1));
	// std::cout<<"\ntest2 est un objet de type : ";
	identify(&(*test2));
	// std::cout<<"\ntest3 est un objet de type : ";
	identify(&(*test3));

	delete test1;
	delete test2;
	delete test3;
	return 0;
}
