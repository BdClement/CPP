/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:31 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/12 19:40:23 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Remplacable par #pragma once
#ifndef __PMERGEME__H__
#define __PMERGEME__H__

#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

// template <typename Container>
class PmergeMe
{
	public:
	PmergeMe(char **arg);
	PmergeMe(PmergeMe const& asign);
	~PmergeMe();
	PmergeMe & operator=(PmergeMe const& equal);

	void	print_data();// TEST
	bool	is_valid_number(std::string const& str) const;
	int		atoi_convert(const char *str) const;

	// template <typename element>
	// void	ford_johnson_algorithm(element first, element last);// envoi de m_data iterateur begin et end

	private:
	// Container	m_data;
	std::vector<int>	m_data;
	//Attribut pour gerer le temps d'execution
};

#endif
