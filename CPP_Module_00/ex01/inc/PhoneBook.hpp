/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:10 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/06 19:37:59 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include "main_header.hpp"
#include "Contact.hpp"
#include <queue>
#include <iostream>
#include <string>

class PhoneBook
{
	//methodes
	public:

	//add
	//search
	//exit ??

	// attributs
	protected:

	std::queue<class Contact> m_contact_tab[8];
};

#endif
