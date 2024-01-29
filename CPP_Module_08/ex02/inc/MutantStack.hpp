/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:58:54 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/29 17:16:13 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK__HPP
#define __MUTANTSTACK__HPP

#include <stack>
#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack();
	MutantStack(MutantStack & asign);
	virtual ~MutantStack();

	MutantStack & operator=(MutantStack & equal);

	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public :
		iterator();
		iterator(T* begin);
		iterator(const iterator & asign);
		virtual ~iterator();
		typename MutantStack<T>::iterator& operator=(typename MutantStack<T>::iterator const & equal);

		T&	operator*() const;
		typename MutantStack<T>::iterator&	operator++();
		typename MutantStack<T>::iterator&	operator--();
		typename MutantStack<T>::iterator&	operator+(int to_add);
		typename MutantStack<T>::iterator&	operator+=(int to_add);
		typename MutantStack<T>::iterator&	operator-(int to_dec);
		bool	operator!=(const iterator& equal) const;
		bool	operator==(const iterator& equal) const;

		private :
		typename iterator::pointer	ptr;
	};

	iterator	begin();
	iterator	end();

	private:

};

#include "MutantStack.tpp"

template <typename T>
void	increment_value(T &value);// fonction pour tester un for_each

#endif
