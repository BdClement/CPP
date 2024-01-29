/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:58:49 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/29 17:26:21 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main()
{
	{
		std::cout<<"********* Test de la forme canonique de MutantStack *********"<<std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(20);
		MutantStack<int> mstack2;
		mstack2 = mstack;
		MutantStack<int> mstack3(mstack2);
		mstack.pop();
		mstack.pop();
		mstack2.pop();
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout<<"mstack"<<std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		MutantStack<int>::iterator it1 = mstack2.begin();
		MutantStack<int>::iterator ite1 = mstack2.end();
		std::cout<<"mstack2"<<std::endl;
		while (it1 != ite1)
		{
			std::cout << *it1 << std::endl;
			++it1;
		}
		MutantStack<int>::iterator it2 = mstack3.begin();
		MutantStack<int>::iterator ite2 = mstack3.end();
		std::cout<<"mstack3"<<std::endl;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
	}
	{
		std::cout<<"\n\n********* Test du sujet *********"<<std::endl;
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
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout<<"\n\n********* Test du sujet avec une liste *********"<<std::endl;
		std::list<int> lst;
		lst.push_front(5);
		lst.push_front(17);
		std::cout << lst.front() << std::endl;
		lst.pop_front();
		std::cout << lst.size() << std::endl;
		lst.push_front(3);
		lst.push_front(5);
		lst.push_front(737);
		//[...]
		lst.push_front(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(lst);
	}
	{
		std::cout<<"\n\n********* Test de for_each avec les iterateurs de MutantStack *********"<<std::endl;
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);
		mstack.push(0);
		mstack.push(-10);
		std::cout<<"mstack avant le for_each"<<std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		for_each(mstack.begin(), mstack.end(), increment_value<int>);
		std::cout<<"\n\nmstack apres le for_each"<<std::endl;
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::cout<<"Test end = "<<*(--mstack.end())<<std::endl;
	}
	return 0;
}
