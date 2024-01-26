/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:45:45 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/26 13:40:37 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN__HPP
#define __SPAN__HPP

#include <deque>
#include <iostream>
#include <algorithm>

class Span
{
	public:
	Span(unsigned int N);
	Span(Span const& asign);
	~Span();

	Span & operator=(Span const& equal);

	void	print() const;

	void	addNumber(int to_add);
	void	addNumbers(std::deque<int>::iterator start, std::deque<int>::iterator end);

	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	std::deque<int>::iterator	getBegin();
	std::deque<int>::iterator	getEnd();

	private:
	unsigned int		m_stock_max;
	std::deque<int>		m_content;
};

void	print_span_element(int to_print);

#endif
