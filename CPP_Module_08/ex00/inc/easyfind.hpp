/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:14:10 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/24 13:30:53 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND__HPP
#define __EASYFIND__HPP

#include <algorithm>
#include <stdexcept>
#include <queue>
#include <stack>

template<typename T>
int	easyfind(T content, int to_find)
{
	typename T::iterator	it;
	it = find(content.begin(), content.end(), to_find);
	if (it == content.end())
		throw(std::exception());
	return *it;
}

#endif
