/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:21:01 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/22 15:33:11 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER__HPP
#define __WHATEVER__HPP

#include <string>
#include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const&	min(T const& a, T const& b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
T const&	max(T const& a, T const& b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
