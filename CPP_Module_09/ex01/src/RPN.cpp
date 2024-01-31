/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:37:41 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/31 19:54:35 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(RPN const& asign){m_stack = asign.m_stack;}

RPN::~RPN(){}

RPN& RPN::operator=(RPN const & equal)
{
	if (this != &equal)
	{
		this->m_stack = equal.m_stack;
	}
	return *this;
}

// Fonctor to check the all string
struct IsValidChar
{
	bool operator()(char c) const
	{
		return std::isdigit(c) || c == '+' || c == '*' || c == '-' || c == '/' || std::isspace(c);
	}
};

// Check that the argument is not an empty string and contains only accpeted charracter
bool	RPN::isValid(std::string	&operation) const
{
	if (operation.size() == 0)
	{
		std::cout<<"Error : argument given is empty"<<std::endl;
		return false;
	}
	for(std::string::iterator it = operation.begin(); it != operation.end(); ++it)
	{
		IsValidChar check_char;
		if (!check_char(*it))
		{
			std::cout<<"Error : argument given contains bad character"<<std::endl;
			return false;
		}
	}
	return true;
}

bool	RPN::isOperation(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// Traverse the string given as argument and do 2 string
// Either push the digit in the stack if it's a digit
// Or remove the 2 first element of the stack and do the appropriate calcul with them
// Then push the result in the stack
void	RPN::calcul(std::string	operation)
{
	for(std::string::iterator it = operation.begin(); it != operation.end(); ++it)
	{
		if (std::isdigit(*it))
		{
			int	to_push = *it;
			m_stack.push(to_push - 48);
		}
		else if (isOperation(*it))
		{
			if (m_stack.size() < 2)
			{
				std::cout<<"Error : operation is not considered as a valid Reverse Polish Notation"<<std::endl;
				return ;
			}
			this->proceed_calcul(*it);
		}
	}
	// this->display_stack(m_stack);// TEST
	if (m_stack.size() > 1)
	{
		std::cout<<"Error : operation is not considered as a valid Reverse Polish Notation"<<std::endl;
		return ;
	}
	std::cout<<m_stack.top()<<std::endl;
}

// Remove the 2 first elements of the stack and do the appropriate calcul with them
// Then push the result in the stack
void	RPN::proceed_calcul(char c)
{
	int	first = m_stack.top();
	m_stack.pop();
	int	second = m_stack.top();
	m_stack.pop();
	switch (c)
	{
		case '+' :
			m_stack.push(second + first);
			break;
		case '-' :
			m_stack.push(second - first);
			break;
		case '*' :
			m_stack.push(second * first);
			break;
		case '/' :
			m_stack.push(second / first);
			break;
		default :
			break;
	}
}

// Fonction de Test
void	RPN::display_stack(std::stack<int> to_display) const
{
	std::cout<<"Stack ="<<std::endl;
	while (!to_display.empty())
	{
		std::cout<<to_display.top()<<std::endl;
		to_display.pop();
	}
}
