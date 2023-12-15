/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:16 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/15 12:00:08 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.hpp"
#include "PhoneBook.hpp"

// Constructor by default
PhoneBook::PhoneBook()
{
	m_nb_contact = 0;
}

/////////////////////// ADD Command /////////////////////
void	PhoneBook::executeAdd()
{
	newContact();
	std::cout << std::endl;
}

void	PhoneBook::newContact()
{
	Contact	ajout;

	ajout.setContact();
	pushContact(ajout);
}

void	PhoneBook::pushContact(Contact &new_contact)
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
void	PhoneBook::excecuteSearch()
{
	if (m_nb_contact != 0)
	{
		int	toBeDisplayed;
		displayPhoneBook();
		std::cout << "Entrez l'index du contact que vous souhaitez consulter : ";
		if (std::cin >> toBeDisplayed)
			displayContact(toBeDisplayed);
		else
		{
			std::cout << "Ceci n'est pas un nombre enier valide" << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
void	PhoneBook::displayContact(int index) const
{
	if (index < 0 or index > m_nb_contact - 1 or index > 7)
		std::cout << "L'index est incorrect" << std::endl;
	else
		m_contact_tab[index].displayContact();
}
