/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:32:58 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/12 19:14:03 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME__TPP
#define __PMERGEME__TPP

#include "PmergeMe.hpp"

template<typename Container>
PmergeMe<Container>::PmergeMe(char **arg)
{
	// Init les attibuts pour le temps
	for (int i = 0; data[i]; i++)
	{
		if(!is_valid_number(data[i]))
			throw std::invalid_argument("Error invalid input");
		m_data.push_back(data[i]); // Conversion string en int
	}
}

template<typename Container>
PmergeMe::PmergeMe(PmergeMe const& asign)
{
	m_data = asign.m_data;
}

template<typename Container>
PmergeMe::~PmergeMe(){}

template<typename Container>
PmergeMe& PmergeMe::operator=(PmergeMe const & equal)
{
	if (this != &equal)
	{
		m_data = equal.m_data;
		// Atibuts pour le temps a copier egalement
	}
	return *this;
}

template<typename Container>
bool	is_valid_number(std:string const& str) const
{
	if (s.empty() || s[0] == '-')
		return false;
	int i = 0;
	if (s[0] == '+' && s.length() == 1)
		return false;
	else if (s[0] == '+')
		i++;
	for (; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

template<typename Container>
int		atoi_convert(const char *str)const
{
	int	int_value = 0;
	char *endstring;
	long long int long_value = std::strtoll(str, &endstring, 10);
	if (*endstring == '\0' && value >= INT_MIN && value <= INT_MAX)
		int_value = static_cast<int>long_value;
	else
		throw std::invalid_argument("Error int overflow");
	return int_value;
}


#endif
