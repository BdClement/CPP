/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:32:51 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/12 16:30:22 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
    Zombie *tab = new Zombie[5];
    for (int i = 0; i < N; i++)
    {
        tab[i].setName(name);
    }
    return tab;
}
