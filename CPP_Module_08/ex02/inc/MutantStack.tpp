/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:36:07 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/29 20:08:56 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK__TPP
#define __MUTANTSTACK__TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(MutantStack & asign) : std::stack<T>(asign)
{
	// *this = asign;
	// for (MutantStack<T>::iterator it = asign.end() - 1; it != asign.begin() - 1 ; --it)
	// 	this->push(*it);
}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack & equal)
{
	if (this != &equal)
	{
		std::stack<T>::operator=(equal);
		return *this;
	}
		// *this = equal;
	return *this;
	// while (this->size() != 0)
	// 	this->pop();
	// for (MutantStack<T>::iterator it = equal.end() - 1; it != equal.begin() - 1; --it)
	// 	this->push(*it);
	// return *this;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	// return iterator(&this->top());
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
	// typename MutantStack<T>::iterator it = this->begin();
	// std::advance(it, this->size());
	// return it;
}

// template<typename T>
// typename MutantStack<T>::iterator	MutantStack<T>::begin()
// {
// 	return iterator(&this->top());
// 	return (std::stack::value_type begin());
// }

// template<typename T>
// typename MutantStack<T>::iterator	MutantStack<T>::end()
// {
// 	typename MutantStack<T>::iterator it = this->begin();
// 	std::advance(it, this->size());
// 	return it;
// }

//*********************** Class interne iterator ***********************//

// template<typename T>
// MutantStack<T>::iterator::iterator() :ptr(NULL) {}

// template<typename T>
// MutantStack<T>::iterator::iterator(T* begin) : ptr(begin){}

// template<typename T>
// MutantStack<T>::iterator::iterator(const iterator & asign): ptr(asign.ptr){}

// template<typename T>
// MutantStack<T>::iterator::~iterator(){}

// template<typename T>
// typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(typename MutantStack<T>::iterator const & equal)
// {
// 	if (this != &equal)
// 		this->ptr = equal.ptr;
// 	return *this;
// }

// template<typename T>
// T&	MutantStack<T>::iterator::operator*() const
// {
// 	return *ptr;
// }

// template<typename T>
// typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator++()
// {
// 	--ptr;
// 	return *this;
// }

// template<typename T>
// typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator--()
// {
// 	++ptr;
// 	return *this;
// }

// template<typename T>
// typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator+(int to_add)
// {
// 	ptr -= to_add;
// 	return *this;
// }

// template<typename T>
// typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator+=(int to_add)
// {
// 	ptr -= to_add;
// 	return *this;
// }

// template<typename T>
// typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator-(int to_dec)
// {
// 	ptr += to_dec;
// 	return *this;
// }

// template<typename T>
// bool	MutantStack<T>::iterator::operator!=(const iterator& equal) const
// {
// 	return this->ptr != equal.ptr;
// }

// template<typename T>
// bool	MutantStack<T>::iterator::operator==(const iterator& equal) const
// {
// 	return this->ptr == equal.ptr;
// }

//*********************** Fonction pour tester les iterateurs avec un for_each ***********************//
template <typename T>
void	increment_value(T &value)
{
	value++;
}

#endif
