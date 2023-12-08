/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:16 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/08 20:02:04 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.hpp"
#include "PhoneBook.hpp"

// Constructeur par defaut
PhoneBook::PhoneBook()
{

}

void	PhoneBook::newContact(void)
{
	Contact	ajout;

	ajout.setContact();
	// ajout.afficher();
	// ajout.resizeAttr();
	m_queue_contact.push(ajout);
	if (m_queue_contact.size() > 8)
		m_queue_contact.pop();
}

void	PhoneBook::displayIndex(int index)
{
	m_contact_tab[index].displayFull();
}

void	PhoneBook::displayTab() const
{
	std::cout << "     Index|First name| Last name|  Nickname"<< std::endl;
	for( int i = 0; i <= (int)m_queue_contact.size() - 1; i++)
	{
		std::ostringstream oss;
		oss << i;
		std::string indexStr = oss.str();
		displayResizedStr(indexStr);
		// Display resized index
		std::cout << "|";
		m_contact_tab[i].displayPart();
		std::cout << std::endl;
	}
}

void	PhoneBook::displayQueue() const
{
	std::queue<Contact> queue_temp = m_queue_contact;
	while (!queue_temp.empty())
	{
		queue_temp.front().displayPart();
		queue_temp.pop();
	}
	std::cout << std::endl;
}

void	PhoneBook::fillTab()
{
	std::queue<Contact> queue_temp = m_queue_contact;

	while (!queue_temp.empty())
	{
		m_contact_tab[queue_temp.size() - 1] = queue_temp.front();
		queue_temp.pop();
	}
}
