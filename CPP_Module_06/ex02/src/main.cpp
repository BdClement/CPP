/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:54:25 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/19 14:06:50 by clbernar         ###   ########.fr       */
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


	// Test de la fonction identify avec pointeur
	std::cout<<"test1 est un objet de type : ";
	identify(test1);
	std::cout<<"test2 est un objet de type : ";
	identify(test2);
	std::cout<<"test3 est un objet de type : ";
	identify(test3);

	// Test de la fonction identify avec adresse
	std::cout<<"\ntest1 est un objet de type : ";
	identify(&(*test1));
	std::cout<<"test2 est un objet de type : ";
	identify(&(*test2));
	std::cout<<"test3 est un objet de type : ";
	identify(&(*test3));

	delete test1;
	delete test2;
	delete test3;
	return 0;
}
