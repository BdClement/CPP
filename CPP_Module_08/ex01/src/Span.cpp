/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:55:00 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/26 13:40:24 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : m_stock_max(N){}
Span::Span(Span const& asign) : m_stock_max(asign.m_stock_max)
{
	m_content.assign(asign.m_content.begin(), asign.m_content.end());
}
Span::~Span(){}
Span& Span::operator=(Span const & equal)
{
	if (this != &equal)
	{
		m_stock_max = equal.m_stock_max;
		m_content.clear();
		m_content.assign(equal.m_content.begin(), equal.m_content.end());
		// Copy peut etre utilise
	}
	return *this;
}

void	Span::addNumber(int to_add)
{
	try
	{
		if (m_content.size() == m_stock_max)
			throw std::exception();
		m_content.push_front(to_add);
	}
	catch (const std::exception&)
	{
		std::cout<<"Exception catched : The container is full"<<std::endl;
	}
}

void	Span::addNumbers(std::deque<int>::iterator start, std::deque<int>::iterator end)
{
	try
	{
		if (m_stock_max < m_content.size() + (end - start))
			throw std::exception();
		m_content.insert(m_content.end(), start, end);
	}
		catch (const std::exception&)
	{
		std::cout<<"Exception catched : The container is full"<<std::endl;
	}
}

unsigned int	Span::shortestSpan()
{
	if (m_content.size() < 2)
		throw std::exception();
	unsigned int	shortest = Span::longestSpan(), count = 0;
	for (std::deque<int>::iterator it = m_content.begin(); it != m_content.end(); ++it)
	{
		if (count != 0)
		{
			if (shortest > static_cast<unsigned int> (*it - *(it - 1)))
				shortest = static_cast<unsigned int> (*it - *(it - 1));
		}
		count++;
	}
	return shortest;
}

unsigned int	Span::longestSpan()
{
	if (m_content.size() < 2)
		throw std::exception();
	sort(m_content.begin(), m_content.end());
	return (*(m_content.end() - 1) - *(m_content.begin()));
}

std::deque<int>::iterator	Span::getBegin()
{
	return m_content.begin();
}

std::deque<int>::iterator	Span::getEnd()
{
	return m_content.end();
}

void	print_span_elem(int to_print)
{
	std::cout<<to_print<<' ';
}

void	Span::print() const
{
	for_each(m_content.begin(), m_content.end(), print_span_elem);
}
