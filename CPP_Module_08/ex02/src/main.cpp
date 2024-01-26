/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:58:49 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/26 21:32:26 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// int	main()
// {
// 	MutantStack<int>	mstack;
// 	mstack.push(5);
// 	mstack.push(10);

// 	MutantStack<int>::iterator	it = mstack.begin();
// 	std::cout<<"Fonction begin : "<<*it<<std::endl;
// 	++it;
// 	std::cout<<"Fonction begin apres incrementation: "<<*it<<std::endl;
// 	--it;
// 	std::cout<<"Fonction begin apres decrementation: "<<*it<<std::endl;
// 	std::cout<<mstack.top()<<std::endl;
// 	return 0;
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end(); // A checker, ca a l'air bon
	// --ite;
	// --ite;
	// --ite;
	// --ite;
	std::cout <<"it = "<< *it<< std::endl;
	std::cout <<"ite = "<< *ite<< std::endl;
	// (void) ite;
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
