/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:21:19 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/17 03:05:17 by Enfoirax         ###   ########.fr       */
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

// void	PmergeMe::print_sorted_data()// TEST
// {
// 	for(std::vector<int>::iterator it = m_sorted_data.begin(); it != m_sorted_data.end(); ++it)
// 		std::cout<<*it<<std::endl;
// }

// // Je pense que cest bon. difficile a voir Binary search needed
// void	PmergeMe::insert_main_chain(std::vector<int>& main_chain)
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
	if (!(begin.get_size() * 2 > m_data.size()))
	{
		new_end--;
		new_end.make_pair();
	}
	// SORT INSIDE PAIRS
	this->sort_pairs(begin, end);
	std::vector<v_element> tmp;
	// RECURSIVITE
	tmp = vector_ford_johnson(new_begin, new_end);
	std::cout<<"Etat de la liste = ";
	this->print_group(begin, end);// TEST
	std::cout<<"\n"<<std::endl;
	// std::vector<GroupIterator<std::vector<int>::iterator> > ret =

	// TRI DE LA SEQUENCE RETOURNE
	return this->sort_sequence(tmp);
}




// Suites de Jacobsthal 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525
std::vector<v_element>	PmergeMe::sort_sequence(std::vector<v_element >& src)
{
	std::cout<<"****  NOUVEAU TOUR ****\n\n"<<std::endl;
	if (src.size() == 0)
		exit(EXIT_FAILURE);
	std::cout<<"Contenu de src_chain = ";
	for (size_t i = 0; i < src.size(); i++)
		std::cout<<*(src[i])<<" -- ";
	std::cout<<"\n"<<std::endl;
	// SPLIT CHAINS
	std::vector<v_element>	main_chain;
	std::vector<v_element>	pend_chain;
	split_pairs(src, main_chain, pend_chain);
	std::vector<v_element> new_main_chain = main_chain;
	// main_chain.insert(main_chain.begin(), pend_chain[0]);
	// AFFICHAGE DES CHAINES OBTENUES
	std::cout<<"Contenu de main_chain = ";
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout<<*(main_chain[i])<<" -- ";
	std::cout<<std::endl;
	std::cout<<"Contenu de pend_chain = ";
	for (size_t i = 0; i < pend_chain.size(); i++)
		std::cout<<*(pend_chain[i])<<" -- ";
	std::cout<<std::endl;
	// INSERTION
	for (size_t i = 0; i < pend_chain.size(); i++)
	{
		int to_insert = find_next_pend(i + 1); // A revoir 
		if (i == 0)
		{
			new_main_chain.insert(new_main_chain.begin(), pend_chain[0]);
			std::cout<<"Insertion du premier"<<std::endl;
		}
		else
		{
			int j = i;
			if (to_insert > (int)pend_chain.size())
				to_insert -= to_insert - i;
			do {

			std::cout<<"\ni = "<<i<<"  j = "<<j<<"  to insert = "<<to_insert;
			std::cout<<"\nnew main chain index"<< j<<" = "<<*new_main_chain[j]<<" < pendchain index "<<to_insert<<" = "<<*pend_chain[to_insert];
				if (*new_main_chain[j] < *pend_chain[to_insert])
				{
					std::cout<<" Vrai \n"<<std::endl;
					new_main_chain.insert(new_main_chain.begin() + (j + 1), pend_chain[to_insert]);
					std::cout<<*pend_chain[to_insert]<<" vient d'etre inserer"<<std::endl;
				}
				else if ( j == 0)
					new_main_chain.insert(new_main_chain.begin() , pend_chain[to_insert]);
				j--;
			} while (j >= 0);
		}
	}
	// Inserer pend dans main
	return new_main_chain;
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


size_t	PmergeMe::find_next_pend(size_t index)
{
	if (index == 0) return 0;
	if (index == 1) return 1;
	std::vector<int> jacobsthal= jacobsthalSequence(20);
	int i = 0;
	while (jacobsthal[i] < (int)index)
		i++;
	int	span = jacobsthal[i] - jacobsthal[i -1];
	int to_decrement = index + span - jacobsthal[i] -1;
	return jacobsthal[i] - to_decrement;
}

void	PmergeMe::split_pairs(std::vector<v_element>& src, std::vector<v_element>& main_chain, std::vector<v_element>& pend_chain)
{
	(void)main_chain;
	for (size_t i = 0; i < src.size(); i++)
	{
		v_element A(src[i].get_iterator(), src[i].get_size() / 2);
		v_element B = A;
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

	// print_group(begin, end); // TEST

void	PmergeMe::sort_pairs(GroupIterator<std::vector<int>::iterator>& begin, GroupIterator<std::vector<int>::iterator>& end)
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
			it++;
		}
	}
}

void	PmergeMe::print_group(v_element begin, v_element end)
{
	// std::cout<<" -- >> "<<*begin;
	//  	std::cout<<" -- >> "<<*end;
	while (begin != end)
	{
		std::cout<<" -- >> "<<*begin;
		begin++;
	}
	std::cout<<" -- >> "<<*begin;
}

// BLOC INITIALEMENT AU DEPLIEMENT DE LA RECURSION
	// Split main and pend chain : Fonction ?
	// std::vector<int>	main_chain;
	// std::vector<int>	pend_chain;
	// for(GroupIterator<std::vector<int>::iterator> it = begin; it < end; ++it)
	// {
	// 	// pend_chain.insert(pend_chain.begin(), *it);
	// 	pend_chain.push_back(*it);
	// 	it++;
	// 	// main_chain.insert(main_chain.begin(), *it);
	// 	main_chain.push_back(*it);
	// }
	// std::cout << "Contenu de main chain : "<<std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i)
	// {
	// 	std::cout << main_chain[i] <<std::endl;
	// }
	// std::cout << "Contenu de pend chain : "<<std::endl;
	// for (size_t i = 0; i < pend_chain.size(); ++i)
	// {
	// 	std::cout << pend_chain[i] <<std::endl;
	// }
	// // Binary Search ( A FAIRE SUR new_begin et new_end et acceder au x et y de chaque paire)
	// this->insert_main_chain(main_chain);
	// this->insert_pend_chain(pend_chain);
	// this->insert_pend_chain(pend_chain, main_chain);
	// std::cout << "Contenu de main chain Apres insertion de pend_chain: "<<std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i)
	// {
	// 	std::cout << main_chain[i] <<std::endl;
	// }
	// std::cout<<"Contenu de sorted_data : "<<std::endl;
	// this->print_sorted_data();
