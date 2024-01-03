/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:35:14 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/03 12:11:43 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout<<"//// Test basique du sujet ////"<<std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete  i;
    delete  j;
    std::cout<<std::endl<<std::endl;

    std::cout<<"//// Test avec les classes WrongCat et WrongAnimal ////"<<std::endl;
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i2 = new WrongCat();
    // const WrongCat* i3 = dynamic_cast<const WrongCat*>(i2);
    std::cout << i2->getType() << " " << std::endl;
    meta2->makeSound();
    i2->makeSound();
    // i3->makeSound();
    delete meta2;
    delete  i2;
    return 0;
}
