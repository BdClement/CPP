/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:13:31 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/24 19:42:49 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	Span test(100000);
	// try
	// {
	// 	test.longestSpan();
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cout<<"Exception catched : The container needs at leat 2 elements"<<std::endl;
	// }
	for (int i = -500; i < 99500; i++)
		test.addNumber(i);
	// test.addNumber(0);
	// test.print();
	std::cout<<"Shortest Span is : "<<test.shortestSpan()<<std::endl;
	std::cout<<"Longest Span is : "<<test.longestSpan()<<std::endl;// a mettre dans un try and catch
	return 0;
}
