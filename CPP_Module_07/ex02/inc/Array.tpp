/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:52:33 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/22 19:54:14 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY__TPP
#define __ARRAY__TPP

#include <stdexcept>
#include <Array.hpp>

template<typename T>
Array<T>::Array() : m_array(new T[0]), m_size(0)
{
	std::cout<<"Array template default constructor called"<<std::endl;
}

template<typename T>
Array<T>::Array(Array const& asign) : m_array(new T[asign.size()]), m_size(asign.size())
{
	std::cout<<"Array template copy constructor called"<<std::endl;
	for (unsigned int i = 0; i < asign.size(); i++)
		m_array[i] = asign.m_array[i];
}

template<typename T>
Array<T>::~Array()
{
	std::cout<<"Array template destructor called"<<std::endl;
	delete[] m_array;
}

template<typename T>
Array<T>::Array(unsigned int	n)
{
	std::cout<<"Array template (unsigned int) constructor called"<<std::endl;
	m_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		m_array[i] = T();
	m_size = n;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const & equal)
{
	std::cout<<"Array template assignation operator called"<<std::endl;
	if (this != &equal)
	{
		delete []this->m_array;
		this->m_array = new T[equal.size()];
		for (unsigned int i = 0; i < equal.size(); i++)
			this->m_array[i] = equal.m_array[i];
		this->m_size = equal.size();
	}
	return *this;
}

template<typename T>
T & Array<T>::operator[](int index)
{
	std::cout<<"Array template indexation operator called"<<std::endl;
	if (index < 0 || index >= (int)this->size())
		throw std::out_of_range("Index is out of bounds");
	return m_array[index];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return m_size;
}

template<typename T>
T*	Array<T>::getArray() const
{
	return m_array;
}

#endif
