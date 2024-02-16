/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:14:21 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/16 22:47:53 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout<<"Error : This program needs a sequence of positive numbers as arguments."<<std::endl;
		return (1);
	}
	try
	{
		PmergeMe	test(argv + 1);
		GroupIterator<std::vector<int>::iterator> begin(test.get_data().begin(), 1);
		GroupIterator<std::vector<int>::iterator> end(test.get_data().end() - 1, 1); // end - 1?
		if (test.get_data().size() > 1)
		{
			std::vector<v_element> result = test.vector_ford_johnson(begin, end);
			std::cout<<"Result : "<<std::endl;
			for (size_t i = 0; i < result.size(); i++)
				std::cout<<*result[i]<<std::endl;
			// test.print_group(result.begin(), result.end());
		}
		// std::cout<<"Begin = "<<*begin<<std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
