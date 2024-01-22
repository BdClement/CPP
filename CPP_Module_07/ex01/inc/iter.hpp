/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:41:26 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/22 16:12:45 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER__HPP
#define __ITER__HPP

#include <string>
#include <iostream>

template<typename T, typename U>
void	iter(T* array, unsigned int size, U (*function)(T))
{
	for (unsigned int i = 0; i < size; i++)
		function(array[i]);
}

template<typename T>
void	print(T toPrint)
{
	std::cout<<toPrint<<std::endl;
}

template<typename T>
double	printDouble(double toPrint)
{
	std::cout<<toPrint<<std::endl;
	return toPrint;
}

template<typename T>
void	printString(std::string toPrint)
{
	std::cout<<toPrint<<std::endl;
}
#endif
