/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:26:20 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/19 14:07:17 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base(){}

Base * generate(void)
{
    // Initialisation du générateur de nombres aléatoires
    std::srand(static_cast<unsigned>(std::time(0)));
    // Génération d'un nombre aléatoire entre 0 et 2 inclus
    int randomValue = std::rand() % 3;
    // Actions possibles
    switch (randomValue)
    {
        case 0:
        {
            // Checker en retournant direct un static_cast
            A * instanceA = new A();
            Base *aBasePtr = instanceA;
            return  aBasePtr;
        }
        case 1:
        {
            B * instanceB = new B();
            Base    *bBasePtr = instanceB;
            return bBasePtr;
        }
        case 2:
        {
            C * instanceC = new C();
            Base    *cBasePtr = instanceC;
            return cBasePtr;
        }
    }
    return NULL;
}

void identify(Base* p)
{
// It prints the actual type of the object pointed to by p: "A", "B" or "C".
    A * a = dynamic_cast<A *>(p);
    B * b = dynamic_cast<B *>(p);
    C * c = dynamic_cast<C *>(p);
    if (a != NULL)
        std::cout<<"A"<<std::endl;
    else if (b != NULL)
        std::cout<<"B"<<std::endl;
    else if (c != NULL)
        std::cout<<"C"<<std::endl;
    else
        std::cout<<"ERROR"<<std::endl;
}

void identify(Base& p)
{
// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// Using a pointer inside this function is forbidden.
    try
    {
        A &   a = dynamic_cast<A &>(p);
        (void)a;
        std::cout<<"A"<<std::endl;
    }
    catch(const std::exception& e)
    {}
    try
    {
        B &   b = dynamic_cast<B &>(p);
        (void)b;
        std::cout<<"B"<<std::endl;
    }
    catch(const std::exception& e)
    {}
    try
    {
        C &   c = dynamic_cast<C &>(p);
        (void)c;
        std::cout<<"C"<<std::endl;
    }
    catch(const std::exception& e)
    {}
}
