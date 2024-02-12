/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:21:19 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/12 19:38:45 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// template<typename Container>
PmergeMe::PmergeMe(char **arg)
{
	// Init les attibuts pour le temps
	for (int i = 0; arg[i]; i++)
	{
		if(!is_valid_number(arg[i]))
			throw std::invalid_argument("Error invalid input");
		m_data.push_back(atoi_convert(arg[i])); // Conversion string en int
	}
}

// template<typename Container
PmergeMe::PmergeMe(PmergeMe const& asign)
{
	m_data = asign.m_data;
}

// template<typename Container>
PmergeMe::~PmergeMe(){}

// template<typename Container>
PmergeMe& PmergeMe::operator=(PmergeMe const & equal)
{
	if (this != &equal)
	{
		m_data = equal.m_data;
		// Atibuts pour le temps a copier egalement
	}
	return *this;
}

// template<typename Container>
bool	PmergeMe::is_valid_number(std::string const& str) const
{
	if (str.empty() || str[0] == '-')
		return false;
	size_t i = 0;
	if (str[0] == '+' && str.length() == 1)
		return false;
	else if (str[0] == '+')
		i++;
	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

// template<typename Container>
int		PmergeMe::atoi_convert(const char *str)const
{
	int	int_value = 0;
	char *endstring;
	long long int long_value = std::strtoll(str, &endstring, 10);
	if (*endstring == '\0' && long_value >= INT_MIN && long_value <= INT_MAX)
		int_value = static_cast<int>(long_value);
	else
		throw std::invalid_argument("Error int overflow");
	return int_value;
}

void	PmergeMe::print_data()
{
	for(std::vector<int>::iterator it = m_data.begin(); it != m_data.end(); ++it)
		std::cout<<*it<<std::endl;
}
