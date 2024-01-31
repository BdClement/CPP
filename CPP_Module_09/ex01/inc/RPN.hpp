/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:35:57 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/31 19:41:42 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN__HPP
#define __RPN__HPP

#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
	public:
	RPN();
	RPN(RPN const& asign);
	~RPN();

	RPN & operator=(RPN const& equal);

	bool	isValid(std::string	&operation) const;
	bool	isOperation(char c) const;
	void	calcul(std::string	operation);
	void	proceed_calcul(char c);

	void	display_stack(std::stack<int> to_display) const;
	private:
	std::stack<int>	m_stack;
};

#endif
