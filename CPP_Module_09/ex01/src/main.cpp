/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:01:44 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/31 19:47:23 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout<<"This program required one argument"<<std::endl;
	else
	{
		std::string operation(argv[1]);
		RPN	rpn;
		if (rpn.isValid(operation))
			rpn.calcul(operation);
	}
	return 0;
}
