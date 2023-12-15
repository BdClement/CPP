/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:10 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/15 18:41:17 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <cstdlib>
#include "Contact.hpp"

#define MAX_CONTACT 8

class PhoneBook
{
	public:
	PhoneBook();

	void	newContact();
	void	putContactInPhoneBook(Contact &new_contact);
	void	Search();
	void	displayPhoneBook() const;
	void	displayContact(std::string index) const;

	static void	displayResizedStr(std::string resized);

	private:
	Contact	m_contact_tab[MAX_CONTACT];
	int		m_nb_contact;
};

#endif
