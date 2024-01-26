/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:36:07 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/26 21:32:15 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK__TPP
#define __MUTANTSTACK__TPP

#include "MutantStack.hpp"

// template<typename T>
// iterator& MutantStack<T>::operator=(iterator const & equal)
// {
// 	if (this != &equal)
// 	{
// 		ptr = equal.ptr;
// 	}
// 	return *this;
// }

template<typename T>
MutantStack<T>::iterator::iterator(T* begin) : ptr(begin){}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return iterator(&this->top());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	typename MutantStack<T>::iterator it = this->begin();
	for (size_t i = 0; i< this->size(); i++)
		++it;
	return it;
	// return iterator(this->begin() + this->size());
}


template<typename T>
T&	MutantStack<T>::iterator::operator*() const
{
	return *ptr;
}

template<typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator++()
{
	--ptr;
	return *this;
}

// template<typename T>
// typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator+(int to_add)
// {
// 	ptr += to_add;
// 	return *this;
// }

template<typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator--()
{
	++ptr;
	return *this;
}

template<typename T>
bool	MutantStack<T>::iterator::operator!=(const iterator& equal) const
{
	return this->ptr != equal.ptr;
}


#endif
