/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:21:19 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/14 19:12:36 by clbernar         ###   ########.fr       */
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

void	PmergeMe::print_data()// TEST
{
	for(std::vector<int>::iterator it = m_data.begin(); it != m_data.end(); ++it)
		std::cout<<*it<<std::endl;
}

void	PmergeMe::print_sorted_data()// TEST
{
	for(std::vector<int>::iterator it = m_sorted_data.begin(); it != m_sorted_data.end(); ++it)
		std::cout<<*it<<std::endl;
}

// Je pense que cest bon. difficile a voir Binary search needed
// void	PmergeMe::insert_in_sorted_data(std::vector<int>& main_chain)
// {
// 	std::cout<<"Insertion dans sorted = ";
// 	for (size_t i = 0; i < main_chain.size(); i++)
// 	{
// 		if (i >= m_sorted_data.size())
// 		{
// 			m_sorted_data.push_back(main_chain[i]);
// 			std::cout<<main_chain[i]<<" - ";
// 		}
// 	}
// 	std::cout<<std::endl;
// }

std::vector<int>&	PmergeMe::get_data()
{
	return m_data;
}

void	PmergeMe::vector_ford_johnson(GroupIterator<std::vector<int>::iterator>& begin, GroupIterator<std::vector<int>::iterator>& end)
{
	if (begin.get_size() * 2 > m_data.size())
		return;
	// MAKE PAIR
	GroupIterator<std::vector<int>::iterator> new_begin;
	new_begin = begin;
	new_begin.make_pair();
	GroupIterator<std::vector<int>::iterator> new_end;
	new_end = end;
	if (!(begin.get_size() * 2 > m_data.size()))
	{
		new_end--;
		new_end.make_pair();
	}
	// Sort inside pairs
	this->sort_pairs(begin, end);
	vector_ford_johnson(new_begin, new_end);
	// Split main and pend chain : Fonction ?
	std::vector<int>	main_chain;
	std::vector<int>	pend_chain;
	for(GroupIterator<std::vector<int>::iterator> it = begin; it < end; ++it)
	{
		pend_chain.insert(pend_chain.begin(), *it);
		it++;
		main_chain.insert(main_chain.begin(), *it);
	}
	std::cout << "Contenu de main chain : "<<std::endl;
	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		std::cout << main_chain[i] <<std::endl;
	}
	std::cout << "Contenu de pend chain : "<<std::endl;
	for (size_t i = 0; i < pend_chain.size(); ++i)
	{
		std::cout << pend_chain[i] <<std::endl;
	}
	// Binary Search
	// this->insert_in_sorted_data(main_chain);
	// std::cout<<"Contenu de sorted_data : "<<std::endl;
	// this->print_sorted_data();
	// print_group(begin, end); // TEST
	std::cout<<"\n\n\n"<<std::endl;
}

void	PmergeMe::sort_pairs(GroupIterator<std::vector<int>::iterator>& begin, GroupIterator<std::vector<int>::iterator>& end)
{
		// Trier l'interieur de chaque paire
	for (GroupIterator<std::vector<int>::iterator> it = begin; it < end; ++it)
	{
		// Comparaison et échange si nécessaire
		GroupIterator<std::vector<int>::iterator> next_it = it;
		++next_it;
		if (*next_it < *it)
		{
			std::swap_ranges(it.get_iterator(), it.get_iterator() + it.get_size(), next_it.get_iterator());
			it++;
		}
	}
}

void	PmergeMe::print_group(GroupIterator<std::vector<int>::iterator> begin, GroupIterator<std::vector<int>::iterator> end)
{
	while (begin != end)
	{
		std::cout<<" -- >> "<<*begin;
		begin++;
	}
	std::cout<<" -- >> "<<*begin;
}
