/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:44:06 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/12 16:28:04 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *tab = zombieHorde(5, "ZOmbie");
    for (int i = 0; i < 5; i++)
    {
         tab[i].announce();
    }
    //for (int i = 0; i < 5; i++)
    //{
      //  delete &tab[i]; // A checker 
    //}
    delete []tab;
    return 0;
}
