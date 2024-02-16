/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:31 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/16 21:32:15 by clbernar         ###   ########.fr       */
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

typedef GroupIterator<std::vector<int>::iterator> v_element;
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
	std::vector<GroupIterator<std::vector<int>::iterator> >	vector_ford_johnson(v_element& begin, v_element& end);
	void	sort_pairs(GroupIterator<std::vector<int>::iterator>& begin, GroupIterator<std::vector<int>::iterator>& end);
	std::vector<GroupIterator<std::vector<int>::iterator> >	sort_sequence(std::vector<GroupIterator<std::vector<int>::iterator> >& src);
	void	split_pairs(std::vector<v_element>& src, std::vector<v_element>& main_chain, std::vector<v_element>& pend_chain);
	// void	insert_main_chain(std::vector<int>& main_chain);
	// void	insert_pend_chain(std::vector<int>& pend_chain);
	// void	insert_pend_chain(std::vector<int>& pend_chain, std::vector<int>& main_chain);

	size_t	get_jacobsthal(size_t nb);
	std::vector<int> jacobsthalSequence(int n);
	size_t	find_next_pend(size_t index);


	private:

	std::vector<int>	m_data;
	// std::vector<int>	m_sorted_data;
	//Attribut pour gerer le temps d'execution
};

#endif
