/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:10 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/11 17:01:57 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include "main_header.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

class PhoneBook
{
	public:
	PhoneBook();
	// ~Destructeur inutile puisque pas de new

	void	executeAdd();
	void	newContact();
	void	pushContact(Contact &new_contact);
	void	excecuteSearch();
	void	displayPhoneBook() const;
	void	displayContact(int);
	void	addContact();

	protected:
	Contact	m_contact_tab[MAX_CONTACT];
	int		m_nb_contact;
};

#endif
