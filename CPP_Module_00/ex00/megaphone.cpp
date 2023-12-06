/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:20:36 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/06 18:14:59 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	int	i = 1;
	(void)av;

	if (ac > 1)
	{
		while (i < ac)
		{
			for (int j = 0;j < (int)strlen(av[i]); j++)
				av[i][j] = toupper(av[i][j]);
			std::cout << av[i];
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
