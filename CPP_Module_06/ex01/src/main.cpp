/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:54:25 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/17 19:55:54 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <string>
#include <iostream>

int	main()
{
	Data	test;
	test.a = 5;
	test.b = 'b';
	test.c = "This is a test";
	Data*	testDataPtr = Serializer::deserialize(Serializer::serialize(&test));
	std::cout<<"adresse de base : "<<&test<<std::endl;
	std::cout<<"deserialize return : "<<testDataPtr<<"\n"<<std::endl;

	std::cout<<"Test des valeurs pointees par le pointeur retourne par deserialize"<<std::endl;
	std::cout<< "DataPtr's int = "<<testDataPtr->a<<std::endl;
	std::cout<< "DataPtr's char = "<<testDataPtr->b<<std::endl;
	std::cout<< "DataPtr's std::string = "<<testDataPtr->c<<"\n"<<std::endl;

	std::cout<<"\nModification des valeurs de la structure"<<std::endl;
	testDataPtr->a++;
	testDataPtr->b++;
	test.c += ".. it seems to be good";
	std::cout<< "DataPtr's newValue int = "<<testDataPtr->a<<std::endl;
	std::cout<< "DataPtr's newValue char = "<<testDataPtr->b<<std::endl;
	std::cout<< "DataPtr's newValue std::string = "<<testDataPtr->c<<std::endl;
	return 0;
}
