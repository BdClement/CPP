/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:31 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/20 14:35:48 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Remplacable par #pragma once
#ifndef __PMERGEME__H__
#define __PMERGEME__H__

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include "GroupIterator.hpp"

typedef GroupIterator<std::vector<int>::iterator> v_element;
typedef GroupIterator<std::deque<int>::iterator> d_element;

class PmergeMe
{
	public:

	PmergeMe(char **arg);
	PmergeMe(PmergeMe const& asign);
	~PmergeMe();
	PmergeMe & operator=(PmergeMe const& equal);

	bool	is_valid_number(std::string const& str) const;
	int		atoi_convert(const char *str) const;
	size_t	get_jacobsthal(size_t nb);
	std::vector<int> jacobsthalSequence(int n);
	size_t	find_next_pend(size_t index, size_t size_to_insert);

	//VECTOR
	std::vector<int>&	get_data();
	size_t	get_size(v_element begin, v_element end) const;
	void	sort_pairs(v_element& begin, v_element& end);
	std::vector<v_element>	vector_ford_johnson(v_element& begin, v_element& end);
	std::vector<v_element>	sort_sequence(std::vector<v_element>& src, v_element& lost);
	void	split_pairs(std::vector<v_element>& src, std::vector<v_element>& main_chain, std::vector<v_element>& pend_chain);
	void	binary_search_and_insert(std::vector<v_element>& new_main_chain, size_t insertion_area, v_element& to_insert);

	// DEQUE
	std::deque<int>&	get_deque_data();
	size_t	get_size(d_element begin, d_element end) const;
	void	sort_pairs(d_element& begin, d_element& end);
	std::deque<d_element>	deque_ford_johnson(d_element& begin, d_element& end);
	std::deque<d_element>	sort_sequence(std::deque<d_element >& src, d_element& lost);
	void	split_pairs(std::deque<d_element>& src, std::deque<d_element>& main_chain, std::deque<d_element>& pend_chain);
	void	binary_search_and_insert(std::deque<d_element>& new_main_chain, size_t insertion_area, d_element& to_insert);

	private:

	std::vector<int>	m_data;
	std::deque<int>		m_deque_data;
	//Attribut pour gerer le temps d'execution
};

#endif
