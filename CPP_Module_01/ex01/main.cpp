/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:44:06 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/13 16:18:13 by clbernar         ###   ########.fr       */
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
    delete []tab;
    return 0;
}
