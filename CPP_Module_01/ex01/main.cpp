/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:44:06 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/18 12:44:41 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *tab = zombieHorde(3, "ZOmbie");
    for (int i = 0; i < 3; i++)
    {
         tab[i].announce();
    }
    delete []tab;
    return 0;
}
