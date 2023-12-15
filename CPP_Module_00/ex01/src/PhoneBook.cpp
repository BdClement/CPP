/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:16 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/15 18:46:04 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor by default
PhoneBook::PhoneBook()
{
	m_nb_contact = 0;
}

/////////////////////// ADD Command /////////////////////

void	PhoneBook::newContact()
{
	Contact	ajout;

	ajout.setContact();
	putContactInPhoneBook(ajout);
	std::cout << std::endl;
}

void	PhoneBook::putContactInPhoneBook(Contact &new_contact)
{
	for(int i = 7; i > 0; i--)
	{
		m_contact_tab[i] = m_contact_tab[i - 1];
	}
	m_contact_tab[0] = new_contact;
	if (m_nb_contact < 8)
		m_nb_contact++;
}

///////////////////////// SEARCH Command //////////////////////
void	PhoneBook::Search()
{
	if (m_nb_contact != 0)
	{
		std::string toBeDisplayed;
		displayPhoneBook();
		std::cout << "Entrez l'index du contact que vous souhaitez consulter : ";
		if (!std::getline(std::cin, toBeDisplayed))
			exit(-1);
		else if (toBeDisplayed.size() != 1 || !isdigit(toBeDisplayed[0]))
		{
			std::cout << "Invalid index" << std::endl;
		}
		else
			displayContact(toBeDisplayed);
	}
	else
		std::cout << "Le repertoire est vide" << std::endl;
	std::cout << std::endl;
}

// Display the PhoneBook with the format asked
void	PhoneBook::displayPhoneBook() const
{
	if (m_nb_contact != 0)
		std::cout << "     Index|First name| Last name|  Nickname"<< std::endl;
	for( int i = 0; i <= m_nb_contact - 1; i++)
	{
		std::ostringstream oss;
		oss << i;
		std::string indexStr = oss.str();
		displayResizedStr(indexStr);
		std::cout << "|";
		m_contact_tab[i].displayContactSearch();
		std::cout << std::endl;
	}
}

// Display all information about a specific Contact
void	PhoneBook::displayContact(std::string index) const
{
	int	num_index =   atoi(index.c_str());
	if (num_index < 0 or num_index > m_nb_contact - 1 or num_index > 7)
		std::cout << "L'index est incorrect" << std::endl;
	else
		m_contact_tab[num_index].displayContact();
}

void	PhoneBook::displayResizedStr(std::string resized)
{
	if(resized.size() > 10)
	{
		resized.resize(9);
		resized.insert(9, ".");
	}
	else if(resized.size() < 10)
	{
		while (resized.size() != 10)
			resized.insert(0, " ");
	}
	std::cout << resized;
}
