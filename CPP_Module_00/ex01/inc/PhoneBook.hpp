/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:10 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/08 19:58:04 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include "main_header.hpp"
#include "Contact.hpp"
#include <queue>
#include <iostream>
#include <string>
#include <sstream>

class PhoneBook
{
	//methodes
	public:
	PhoneBook();
	// ~Destructeur inutile puisque pas de new

	void	newContact();
	void	displayQueue() const;// Pas utile juste TEST
	void	displayTab() const;
	void	fillTab();
	void	displayIndex(int);
	//add
	//search
		//methode en lecture seule donc CONST
	//exit ??

	// attributs
	protected:

	Contact	m_contact_tab[MAX_CONTACT];
	std::queue<Contact>	m_queue_contact;
};

#endif
