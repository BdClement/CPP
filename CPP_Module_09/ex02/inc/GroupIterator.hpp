/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:47:47 by clbernar          #+#    #+#             */
/*   Updated: 2024/02/17 02:33:06 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GROUPITERATOR__HPP
#define __GROUPITERATOR__HPP

template<typename Iterator>
class GroupIterator
{
	public:

    typedef typename std::iterator_traits<Iterator>::reference reference;

	GroupIterator();
	GroupIterator(Iterator it, size_t size);
	GroupIterator(GroupIterator const& asign);
	~GroupIterator();

	GroupIterator & operator=(GroupIterator const& equal);
	// Accessibilite
	reference operator*();
	// Increment
	GroupIterator& operator++();
	GroupIterator& operator+(int to_add);
	GroupIterator operator++(int);
	GroupIterator& operator--();
	GroupIterator operator--(int);
	GroupIterator& operator+=(size_t increment_nb);
	GroupIterator& operator-=(size_t decrement_nb);
	// Access operator
	int operator[](size_t pos);

	//Comparaison
	bool operator!=(const GroupIterator& other) const;
	bool operator==(const GroupIterator& other) const;
	bool operator>(const GroupIterator& other) const;
	bool operator<(const GroupIterator& other) const;

	// Getters
	size_t	get_size() const;
	Iterator get_iterator();

	// Make pair
	void	make_pair();
	void	unmake_pair();


	private:

	Iterator	m_it;
	size_t		m_size;

};

#include "GroupIterator.tpp"

#endif
