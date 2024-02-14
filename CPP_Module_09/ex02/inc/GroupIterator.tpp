/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:14:02 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/14 16:24:30 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GroupIterator.hpp"

template<typename Iterator>
GroupIterator<Iterator>::GroupIterator(){}

template<typename Iterator>
GroupIterator<Iterator>::GroupIterator(Iterator it, size_t size) : m_it(it), m_size(size){}

template<typename Iterator>
GroupIterator<Iterator>::GroupIterator(GroupIterator const& asign): m_it(asign.m_it), m_size(asign.m_size){}

template<typename Iterator>
GroupIterator<Iterator>::~GroupIterator(){}

template<typename Iterator>
GroupIterator<Iterator>& GroupIterator<Iterator>::operator=(GroupIterator const & equal)
{
	if (this != &equal)
	{
		this->m_it = equal.m_it;
		this->m_size = equal.m_size;
	}
	return *this;
}

/////////////////////////////// SURCHARGES D'OPERATEURS ///////////////////////////////
// Accessibilite
template<typename Iterator>
typename GroupIterator<Iterator>::reference GroupIterator<Iterator>::operator*()
{
	return m_it[m_size - 1];
}

// operator -> ???

// increment/decrement
template<typename Iterator>
GroupIterator<Iterator>& GroupIterator<Iterator>::operator++()
{
	m_it += m_size;
	return *this;
}

template<typename Iterator>
GroupIterator<Iterator> GroupIterator<Iterator>::operator++(int)
{
	GroupIterator tmp;
	tmp = *this;
	operator++();
	return tmp;
}

template<typename Iterator>
GroupIterator<Iterator>& GroupIterator<Iterator>::operator--()
{
	m_it -= m_size;
	return *this;
}

template<typename Iterator>
GroupIterator<Iterator> GroupIterator<Iterator>::operator--(int)
{
	GroupIterator tmp;
	tmp = *this;
	operator--();
	return tmp;
}

template<typename Iterator>
GroupIterator<Iterator>& GroupIterator<Iterator>::operator+=(size_t increment_nb)
{
	m_it += m_size * increment_nb;
	return *this;
}

template<typename Iterator>
GroupIterator<Iterator>& GroupIterator<Iterator>::operator-=(size_t decrement_nb)
{
	m_it -= m_size * decrement_nb;
	return *this;
}

// Access operator
template<typename Iterator>
int GroupIterator<Iterator>::operator[](size_t pos)
{
	return m_it[pos *m_size + m_size - 1];
}

// Comparaison
template<typename Iterator>
bool GroupIterator<Iterator>::operator!=(const GroupIterator& other) const
{
		return m_it != other.m_it;
}

template<typename Iterator>
bool GroupIterator<Iterator>::operator==(const GroupIterator& other) const
{
		return m_it == other.m_it;
}

template<typename Iterator>
bool GroupIterator<Iterator>::operator<(const GroupIterator& other) const
{
		return m_it < other.m_it;
}

template<typename Iterator>
bool GroupIterator<Iterator>::operator>(const GroupIterator& other) const
{
		return m_it > other.m_it;
}

// Getters
template<typename Iterator>
size_t	GroupIterator<Iterator>::get_size() const
{
	return m_size;
}

template<typename Iterator>
Iterator GroupIterator<Iterator>::get_iterator()
{
	return m_it;
}

template<typename Iterator>
void	GroupIterator<Iterator>::make_pair()
{
	m_size *= 2;
}
