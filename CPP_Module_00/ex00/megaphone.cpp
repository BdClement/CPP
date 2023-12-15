/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:20:36 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/15 16:09:09 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	int	i = 1;

	if (ac > 1)
	{
		while (i < ac)
		{
			std::string str = av[i];
			for (int j = 0;j < (int)str.size(); j++)
				str[j] = toupper(str[j]);
			std::cout << str;
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
