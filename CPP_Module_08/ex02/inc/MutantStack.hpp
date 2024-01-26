/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:58:54 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/26 21:27:14 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK__HPP
#define __MUTANTSTACK__HPP

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	// MutantStack();
	// MutantStack(MutantStack const& asign);
	// ~MutantStack();

	// MutantStack & operator=(MutantStack const& equal);

	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private :

		public :
		typename iterator::pointer	ptr;
		iterator(T* begin);
		// iterator& MutantStack<T>::operator=(iterator const & equal);
		T&	operator*() const; // operateur de dereferencement
		typename MutantStack<T>::iterator&	operator++();// operateur de pre-incrementation
		// typename MutantStack<T>::iterator&	operator+(int to_add);
		typename MutantStack<T>::iterator&	operator--();// operateur de pre-decrementation
		// bool	operator==(const iterator& equal) const;// operateur d'egalite
		bool	operator!=(const iterator& equal) const;// operateur de difference
	};

	iterator	begin();// const ?
	iterator	end();

	private:

};

#include "MutantStack.tpp"

#endif
