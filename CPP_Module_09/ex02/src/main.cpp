/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:14:21 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/20 14:58:59 by clbernar         ###   ########.fr       */
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
		v_element begin(test.get_data().begin(), 1);
		v_element end(test.get_data().end() - 1, 1);
		d_element	d_begin(test.get_deque_data().begin(), 1);
		d_element	d_end(test.get_deque_data().end() - 1, 1);
		if (test.get_data().size() > 1)
		{
			// VECTOR
			std::cout<<"VECTOR : \n"<<std::endl;
			std::cout<<"Before : ";
			for (size_t i = 0; i < test.get_data().size(); i++)
				std::cout<<test.get_data()[i]<<"  -  ";
			std::cout<<std::endl;
			clock_t start_vector_time = clock();
			std::vector<v_element> result = test.vector_ford_johnson(begin, end);
			clock_t end_vector_time = clock();
			std::cout<<"After :  ";
			for (size_t i = 0; i < result.size(); i++)
				std::cout<<*result[i]<<"  -  ";
			std::cout<<"\n\n"<<std::endl;

			// DEQUE
			std::cout<<"DEQUE : \n"<<std::endl;
			std::cout<<"Before : ";
			for (size_t i = 0; i < test.get_deque_data().size(); i++)
				std::cout<<test.get_deque_data()[i]<<"  -  ";
			std::cout<<std::endl;
			clock_t start_deque_time = clock();
			std::deque<d_element> deque_result = test.deque_ford_johnson(d_begin, d_end);
			clock_t end_deque_time = clock();
			std::cout<<"After :  ";
			for (size_t i = 0; i < deque_result.size(); i++)
				std::cout<<*deque_result[i]<<"  -  ";
			std::cout<<"\n\n"<<std::endl;

			// TIME
			double elapsed_vector_seconds = static_cast<double>(end_vector_time - start_vector_time) / CLOCKS_PER_SEC;
			double elapsed_deque_seconds = static_cast<double>(end_deque_time - start_deque_time) / CLOCKS_PER_SEC;
			std::cout<<"Time to process a range of "<<test.get_data().size()<<" elements with std::vector : "<< elapsed_vector_seconds * 1000<<" ms"<<std::endl;
			std::cout<<"Time to process a range of "<<test.get_deque_data().size()<<" elements with std::deque : "<<elapsed_deque_seconds * 1000<<" ms"<<std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

