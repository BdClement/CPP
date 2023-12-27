/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:35:14 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/27 16:56:16 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    // AAnimal test;
    std::cout<<"Tests en creant un tableau d'objets AAnimal\nLa moitie sont des Dogs, l'autre moitie sont des Cats\n"<<std::endl;
    std::cout<<"INITIALISATION"<<std::endl;
    AAnimal* tab_animal[6];
    for (int i = 0; i < 3; i++)
        tab_animal[i] = new Dog;
    for (int i = 3; i < 6; i++)
        tab_animal[i] = new Cat;
    std::cout<<std::endl<<std::endl;

    std::cout<<"Appel de la methode vitruelle"<<std::endl;
    for (int i = 0; i < 6; i++)
        tab_animal[i]->makeSound();
    std::cout<<std::endl<<std::endl;


    std::cout<<"DELETE LE TABLEAU"<<std::endl;
    for (int i = 0; i < 6; i++)
        delete tab_animal[i];
    std::cout<<std::endl<<std::endl;

    std::cout<<"Test de la copie profonde"<<std::endl;
    Dog basic;
    basic.affectIdeas("Une idee", 0);
    {
    Dog tmp = basic;
    }
    std::cout<< basic.getIdeas(0) <<std::endl;
    std::cout<<std::endl<<std::endl;
    return 0;
}
