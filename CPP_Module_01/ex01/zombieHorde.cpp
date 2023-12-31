/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:32:51 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/15 19:38:03 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
    Zombie *tab = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        tab[i].setName(name);
    }
    return tab;
}
