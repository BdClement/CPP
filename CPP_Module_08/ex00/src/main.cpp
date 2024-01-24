/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:50 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/24 13:39:35 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

void	print(int to_print)
{
	std::cout<<to_print<<' ';
}

int	main()
{
	std::cout<<"************* Test with vector *************"<<std::endl;
	std::vector<int>	v;
	v.push_back(6);
	v.push_back(2);
	v.push_back(50);
	v.push_back(10);
	v.push_back(5);
	std::cout<<"Affichage vector : ";
	for_each(v.begin(), v.end(), print);
	try
	{
		std::cout<< "\n10 is searched : " <<easyfind(v, 10)<<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout<<"Exception catch : the number is not present in the container"<<std::endl;
	}
	std::cout<<"\n\n************* Test with deque *************"<<std::endl;
	std::deque<int>	d;
	d.push_front(59);
	d.push_front(0);
	d.push_front(-38);
	std::cout<<"Affichage deque : ";
	for_each(d.begin(), d.end(), print);
	try
	{
		std::cout<< "\n10 is searched : " <<easyfind(d, 10)<<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout<<"Exception catch : the number is not present in the container"<<std::endl;
	}
	std::cout<<"\n\n************* Test with list *************"<<std::endl;
	std::list<int>	l;
	for (int i = 1; i < 11; i++)
		l.push_back(i);
	std::cout<<"Affichage list : ";
	for_each(l.begin(), l.end(), print);
	try
	{
		std::cout<< "\n10 is searched : " <<easyfind(l, 10)<<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout<<"Exception catch : the number is not present in the container"<<std::endl;
	}
	return 0;
}
