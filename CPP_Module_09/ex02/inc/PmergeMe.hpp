/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:31 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/19 19:01:33 by clbernar         ###   ########.fr       */
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

	std::vector<GroupIterator<std::vector<int>::iterator> >	vector_ford_johnson(v_element& begin, v_element& end);
	void	sort_pairs(GroupIterator<std::vector<int>::iterator>& begin, GroupIterator<std::vector<int>::iterator>& end);
	std::vector<GroupIterator<std::vector<int>::iterator> >	sort_sequence(std::vector<GroupIterator<std::vector<int>::iterator> >& src, v_element& lost);
	void	split_pairs(std::vector<v_element>& src, std::vector<v_element>& main_chain, std::vector<v_element>& pend_chain);

	size_t	get_jacobsthal(size_t nb);
	std::vector<int> jacobsthalSequence(int n);
	size_t	find_next_pend(size_t index, size_t size_to_insert);
	size_t	get_insertion_area(v_element& to_find, std::vector<v_element>& new_main_chain);
	void	binary_search_and_insert(std::vector<v_element>& new_main_chain, size_t insertion_area, v_element& to_insert);

	size_t	get_size(v_element begin, v_element end) const;

	private:

	std::vector<int>	m_data;
	//Attribut pour gerer le temps d'execution
};

#endif
