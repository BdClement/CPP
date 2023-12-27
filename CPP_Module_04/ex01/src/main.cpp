/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:35:14 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/27 16:01:35 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout<<"TEST BASIQUE DU SUJET"<<std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    std::cout<<std::endl<<std::endl;

    std::cout<<"Tests en creant un tableau d'objets Animal\nLa moitie sont des Dogs, l'autre moitie sont des Cats\n"<<std::endl;
    std::cout<<"INITIALISATION"<<std::endl;
    Animal* tab_animal[6];
    for (int i = 0; i < 3; i++)
        tab_animal[i] = new Dog;
    for (int i = 3; i < 6; i++)
        tab_animal[i] = new Cat;
    std::cout<<std::endl<<std::endl;

    std::cout<<"DELETE LE TABLEAU"<<std::endl;
    for (int i = 0; i < 6; i++)
        delete tab_animal[i];
    std::cout<<std::endl<<std::endl;

    std::cout<<"Test de l'operateur d'affectation sur des Dogs"<<std::endl;
    Dog* test_dog = new Dog;
    test_dog->affectIdeas("Et si je testait la copie profonde mon operateur d'affectation", 0);
    Dog test_dog2;
    test_dog2 = *test_dog;
    std::cout<<std::endl;

    std::cout<<"Test du constructeur de copie sur des Cats"<<std::endl;
    Cat* test_cat = new Cat;
    test_cat->affectIdeas("Et si je testait la copie profonde de mon constructeur de copie", 0);
    Cat test_cat2(*test_cat);
    std::cout<<std::endl<<std::endl;

    std::cout<<"Test que la copie est profonde et non superficielle"<<std::endl;
    std::cout<<"Delete de mon dog et mon cat copie"<<std::endl;
    delete test_dog;
    delete test_cat;
    std::cout<<"Les idees de mes copies sont toujours presentes : \n"<<std::endl;
    std::cout<< test_dog2.getIdeas(0)<<std::endl;
    std::cout<< test_cat2.getIdeas(0)<<"\n"<<std::endl;
    std::cout<<std::endl<<std::endl;

    std::cout<<"Dernier test"<<std::endl;
    Dog basic;
    basic.affectIdeas("Une idee", 0);
    {
    Dog tmp = basic;
    }
    std::cout<< basic.getIdeas(0) <<std::endl;
    std::cout<<std::endl<<std::endl;
    return 0;
}
