/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:44:06 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/18 12:37:53 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *heap = newZombie("Heap");
    heap->announce();
    Zombie  stack("Stack");
    randomChump("Random Chump");
    delete heap;
    return 0;
}
