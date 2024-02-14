/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:31 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/14 19:10:52 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Remplacable par #pragma once
#ifndef __PMERGEME__H__
#define __PMERGEME__H__

#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include "GroupIterator.hpp"

// template <typename Container>
class PmergeMe
{
	public:
	PmergeMe(char **arg);
	PmergeMe(PmergeMe const& asign);
	~PmergeMe();
	PmergeMe & operator=(PmergeMe const& equal);

	void	print_data();// TEST
	void	print_group(GroupIterator<std::vector<int>::iterator> begin, GroupIterator<std::vector<int>::iterator> end); // TEST
	void	print_sorted_data();// TEST

	bool	is_valid_number(std::string const& str) const;
	int		atoi_convert(const char *str) const;
	std::vector<int>&	get_data();

	// template<typename T>
	void	vector_ford_johnson(GroupIterator<std::vector<int>::iterator>& begin, GroupIterator<std::vector<int>::iterator>& end);
	void	sort_pairs(GroupIterator<std::vector<int>::iterator>& begin, GroupIterator<std::vector<int>::iterator>& end);
	void	insert_in_sorted_data(std::vector<int>& main_chain);


	private:

	std::vector<int>	m_data;
	std::vector<int>	m_sorted_data;
	//Attribut pour gerer le temps d'execution
};

#endif
