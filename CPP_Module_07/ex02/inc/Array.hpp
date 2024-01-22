/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:44:42 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/22 19:48:49 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __ARRAY__HPP
#define __ARRAY__HPP


template<typename T>
class Array
{
	public:
	Array();
	Array(unsigned int	n);
	Array(Array const& asign);
	~Array();

	Array & operator=(Array const& equal);
	T & operator[](int	index);
	unsigned int	size() const;
	T*	getArray() const;

	private:
	T				*m_array;
	unsigned int	m_size;

};

#include "Array.tpp"

#endif
