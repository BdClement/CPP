/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:21:19 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/20 14:22:53 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **arg)
{
	// Init les attibuts pour le temps
	for (int i = 0; arg[i]; i++)
	{
		if(!is_valid_number(arg[i]))
			throw std::invalid_argument("Error invalid input");
		m_data.push_back(atoi_convert(arg[i]));
		m_deque_data.push_back(atoi_convert(arg[i]));
	}
}

PmergeMe::PmergeMe(PmergeMe const& asign)
{
	m_data = asign.m_data;
	m_deque_data = asign.m_deque_data;
}

PmergeMe::~PmergeMe(){}

PmergeMe& PmergeMe::operator=(PmergeMe const & equal)
{
	if (this != &equal)
	{
		m_data = equal.m_data;
		m_deque_data = equal.m_deque_data;
		// Atibuts pour le temps a copier egalement
	}
	return *this;
}

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

std::vector<int>&	PmergeMe::get_data()
{
	return m_data;
}

std::deque<int>& PmergeMe::get_deque_data()
{
	return m_deque_data;
}

std::deque<d_element >	PmergeMe::deque_ford_johnson(d_element& begin, d_element& end)
{
	//CONDITION DE FIN DE RECUSRIVITE
	if (begin.get_size() * 2 > m_data.size())
	{
		std::deque<d_element> last;
		last.push_back(begin);
		return last;
	}
	// MAKE PAIR
	d_element new_begin;
	new_begin = begin;
	new_begin.make_pair();
	d_element new_end;
	new_end = end;
	d_element lost;
	// KEEP TRACK OF LOST ELEMENT IF THE SEQUENCE IS ODD
	if (this->get_size(begin, end) % 2 != 0)
	{
		lost = end;
		new_end--;
	}
	if (!(begin.get_size() * 2 > m_data.size()))
	{
		new_end--;
		new_end.make_pair();
	}
	// SORT INSIDE PAIRS
	this->sort_pairs(begin, end);
	// RECURSIVITE
	std::deque<d_element> tmp;
	tmp = deque_ford_johnson(new_begin, new_end);
	// SORT SEQUENCE
	return this->sort_sequence(tmp, lost);
}


std::vector<v_element >	PmergeMe::vector_ford_johnson(v_element& begin, v_element& end)
{
	//CONDITION DE FIN DE RECUSRIVITE
	if (begin.get_size() * 2 > m_data.size())
	{
		std::vector<v_element> last;
		last.push_back(begin);
		return last;
	}
	// MAKE PAIR
	v_element new_begin;
	new_begin = begin;
	new_begin.make_pair();
	v_element new_end;
	new_end = end;
	v_element lost;
	// KEEP TRACK OF LOST ELEMENT IF THE SEQUENCE IS ODD
	if (this->get_size(begin, end) % 2 != 0)
	{
		lost = end;
		new_end--;
	}
	if (!(begin.get_size() * 2 > m_data.size()))
	{
		new_end--;
		new_end.make_pair();
	}
	// SORT INSIDE PAIRS
	this->sort_pairs(begin, end);
	// RECURSIVITE
	std::vector<v_element> tmp;
	tmp = vector_ford_johnson(new_begin, new_end);
	// SORT SEQUENCE
	return this->sort_sequence(tmp, lost);
}

// First the sequence is split. Main_chain contains A et pend_chain B where (B < A) in pairs
// Then, each element of pend chain is inserted in new_main_chain (a copy of main_chain) according
// to the order of insertion given by Jacobsthal sequence
// Finally, lost element if it exists is inserted in new_main_chain which is return
std::vector<v_element>	PmergeMe::sort_sequence(std::vector<v_element >& src, v_element& lost)
{
	if (src.size() == 0)
		exit(EXIT_FAILURE);
	// SPLIT CHAINS
	std::vector<v_element>	main_chain;
	std::vector<v_element>	pend_chain;
	split_pairs(src, main_chain, pend_chain);
	std::vector<v_element> new_main_chain = main_chain;
	// INSERTION
	for (size_t nb_insertion = 0; nb_insertion < pend_chain.size(); nb_insertion++)
	{
		int to_insert = find_next_pend((nb_insertion + 1), pend_chain.size());
		if (nb_insertion == 0)
			new_main_chain.insert(new_main_chain.begin(), pend_chain[to_insert]);
		else
		{
			size_t insertion_area = to_insert + nb_insertion;
			binary_search_and_insert(new_main_chain, insertion_area, pend_chain[to_insert]);
		}
	}
	// Inserer pend dans main
	if (lost.get_size() != 0)
		binary_search_and_insert(new_main_chain, new_main_chain.size(), lost);
	return new_main_chain;
}

// A optimiser / templater
std::deque<d_element>	PmergeMe::sort_sequence(std::deque<d_element >& src, d_element& lost)
{
	if (src.size() == 0)
		exit(EXIT_FAILURE);
	// SPLIT CHAINS
	std::deque<d_element>	main_chain;
	std::deque<d_element>	pend_chain;
	split_pairs(src, main_chain, pend_chain);
	std::deque<d_element> new_main_chain = main_chain;
	// INSERTION
	for (size_t nb_insertion = 0; nb_insertion < pend_chain.size(); nb_insertion++)
	{
		int to_insert = find_next_pend((nb_insertion + 1), pend_chain.size());
		if (nb_insertion == 0)
			new_main_chain.insert(new_main_chain.begin(), pend_chain[to_insert]);
		else
		{
			size_t insertion_area = to_insert + nb_insertion;
			binary_search_and_insert(new_main_chain, insertion_area, pend_chain[to_insert]);
		}
	}
	// Inserer pend dans main
	if (lost.get_size() != 0)
		binary_search_and_insert(new_main_chain, new_main_chain.size(), lost);
	return new_main_chain;
}

void	PmergeMe::binary_search_and_insert(std::vector<v_element>& new_main_chain, size_t insertion_area, v_element& to_insert)
{
	size_t	left = 0;
	size_t	right = insertion_area;
	size_t	mid = 0;

	while (left < right)
	{
		if (right == 0)
			right++;
		mid = left + (right - left) / 2;
		if (*new_main_chain[mid] == *to_insert)
		{
			new_main_chain.insert(new_main_chain.begin() + mid, to_insert);
			return ;
		}
		else if (*new_main_chain[mid] < *to_insert)
			left = mid + 1;
		else
		{
			if (mid == 0)
				break ;
			right = mid - 1;
		}
	}
	if (left == new_main_chain.size())
		left--;
	if (*new_main_chain[left] < *to_insert)
		new_main_chain.insert(new_main_chain.begin() + left + 1, to_insert);
	else
		new_main_chain.insert(new_main_chain.begin() + left, to_insert);
}

void	PmergeMe::binary_search_and_insert(std::deque<d_element>& new_main_chain, size_t insertion_area, d_element& to_insert)
{
	size_t	left = 0;
	size_t	right = insertion_area;
	size_t	mid = 0;

	while (left < right)
	{
		if (right == 0)
			right++;
		mid = left + (right - left) / 2;
		if (*new_main_chain[mid] == *to_insert)
		{
			new_main_chain.insert(new_main_chain.begin() + mid, to_insert);
			return ;
		}
		else if (*new_main_chain[mid] < *to_insert)
			left = mid + 1;
		else
		{
			if (mid == 0)
				break ;
			right = mid - 1;
		}
	}
	if (left == new_main_chain.size())
		left--;
	if (*new_main_chain[left] < *to_insert)
		new_main_chain.insert(new_main_chain.begin() + left + 1, to_insert);
	else
		new_main_chain.insert(new_main_chain.begin() + left, to_insert);
}


// A optimiser
size_t	PmergeMe::get_size(v_element begin, v_element end) const
{
	size_t i = 0;
	while (begin++ < end)
		i++;
	return i + 1;
}

// A optimiser
size_t	PmergeMe::get_size(d_element begin, d_element end) const
{
		size_t i = 0;
	while (begin++ < end)
		i++;
	return i + 1;
}

std::vector<int> PmergeMe::jacobsthalSequence(int n)
{
	std::vector<int> sequence;
	sequence.push_back(0);

	int j_prev = 0;
	int j_curr = 1;
	int j_next;

	for (int i = 1; i < n; ++i)
	{
		sequence.push_back(j_curr);
		j_next = j_curr + 2 * j_prev;
		j_prev = j_curr;
		j_curr = j_next;
	}
	return sequence;
}


size_t	PmergeMe::find_next_pend(size_t insertion_nb, size_t size_to_insert)
{
	if (insertion_nb == 0 || insertion_nb == 1) return 0;
	std::vector<int> jacobsthal= jacobsthalSequence(20);
	int i = 0;
	while (jacobsthal[i] < (int)insertion_nb)
		i++;
	int	span = jacobsthal[i] - jacobsthal[i -1];
	int to_decrement = insertion_nb + span - jacobsthal[i] -1;
	size_t	ret = jacobsthal[i] - to_decrement - 1;
	(void) size_to_insert;
	if (ret + 1 > size_to_insert)
	{
		return  size_to_insert - (insertion_nb - jacobsthal[i - 1]);
	}
	return ret;
}

void	PmergeMe::split_pairs(std::vector<v_element>& src, std::vector<v_element>& main_chain, std::vector<v_element>& pend_chain)
{
	for (size_t i = 0; i < src.size(); i++)
	{
		v_element A(src[i].get_iterator(), src[i].get_size() / 2);
		v_element B = A;
		B++;
		pend_chain.push_back(A);
		main_chain.push_back(B);
	}
}

void	PmergeMe::split_pairs(std::deque<d_element>& src, std::deque<d_element>& main_chain, std::deque<d_element>& pend_chain)
{
	for (size_t i = 0; i < src.size(); i++)
	{
		d_element A(src[i].get_iterator(), src[i].get_size() / 2);
		d_element B = A;
		B++;
		pend_chain.push_back(A);
		main_chain.push_back(B);
	}
}

size_t PmergeMe::get_jacobsthal(size_t n)
{
	if (n > 20)	return 87381;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return get_jacobsthal(n - 1) + 2 * get_jacobsthal(n - 2);
}

// A optimiser
void	PmergeMe::sort_pairs(v_element& begin, v_element& end)
{
		// Trier l'interieur de chaque paire
	for (v_element it = begin; it < end; ++it)
	{
		// Comparaison et échange si nécessaire
		v_element next_it = it;
		++next_it;
		if (*next_it < *it)
		{
			std::swap_ranges(it.get_iterator(), it.get_iterator() + it.get_size(), next_it.get_iterator());
		}
			it++;
	}
}

// A optimiser
void	PmergeMe::sort_pairs(d_element& begin, d_element& end)
{
		// Trier l'interieur de chaque paire
	for (d_element it = begin; it < end; ++it)
	{
		// Comparaison et échange si nécessaire
		d_element next_it = it;
		++next_it;
		if (*next_it < *it)
		{
			std::swap_ranges(it.get_iterator(), it.get_iterator() + it.get_size(), next_it.get_iterator());
		}
			it++;
	}
}
