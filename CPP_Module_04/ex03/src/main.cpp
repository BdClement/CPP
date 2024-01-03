/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:35:14 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/03 13:17:47 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    std::cout<<"////////////////////// Tentative de learn x 6 //////////////////////"<<std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout<<std::endl<<std::endl;

    ICharacter* me = new Character("me");
    std::cout<<"* La Materia source tente 5 create"<<std::endl;
    std::cout<<"Me tente 2x de s'equipe avec ice et 3x avec cure *"<<std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    tmp = src->createMateria("ice");
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->equip(tmp);
    tmp = src->createMateria("cure");
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    std::cout<<std::endl<<std::endl;

    ICharacter* bob = new Character("bob");
    std::cout<<"////////////////////// Me use des materia sur bob //////////////////////"<<std::endl;
    me->use(0, *bob);
    me->use(2, *bob);
    std::cout<<std::endl<<std::endl;

    std::cout<<"////////////////////// Unequip test //////////////////////"<<std::endl;
    me->unequip(1);
    me->use(1, *bob);
    me->unequip(3);
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->use(1, *bob);
    std::cout<<std::endl<<std::endl;

    std::cout<<"////////////////////// Test de la copie profonde //////////////////////"<<std::endl;
    Character* test1 = new Character(*static_cast<Character*>(me));
    Character test2("test2");
    test2 = *static_cast<Character*>(me);
    delete me;
    std::cout<<"////////////////////// Test constructeur de copie //////////////////////"<<std::endl;
    test1->unequip(1);
    test1->use(1, *bob);
    test1->unequip(3);
    test1->equip(tmp);
    test1->equip(tmp);
    test1->equip(tmp);
    test1->use(1, *bob);
    std::cout<<std::endl<<std::endl;
    std::cout<<"////////////////////// Test operateur d'assignation //////////////////////"<<std::endl;
    test2.unequip(1);
    test2.use(1, *bob);
    test2.unequip(3);
    test2.equip(tmp);
    test2.equip(tmp);
    test2.equip(tmp);
    test2.use(1, *bob);
    std::cout<<std::endl<<std::endl;
    delete bob;
    delete test1;
    delete src;
    return 0;
}

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }
