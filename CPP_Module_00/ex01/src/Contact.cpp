/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:47 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/15 18:45:57 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

// Constructor by default
Contact::Contact()
{

}

// Checks if the string is empty or filled whit non alphanumeric char
bool	Contact::isEmpty(std::string str)const
{
	if (str.empty())
		return true;
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (std::isalnum(str[i]))
			return false;
	}
	return true;
}

void	Contact::setContact()
{
	getInfo(m_first_name, "le prenom");
	getInfo(m_last_name, "le nom de famille");
	getInfo(m_nick_name, "le surnom");
	getInfo(m_tel_number, "le numero de telephone");
	getInfo(m_darkest_secret, "le plus lourd secret");
}

// Get Contact's info while the input isEmpty
void	Contact::getInfo(std::string& str, std::string info)
{
	while (isEmpty(str))
	{
		std::cout << "Entrez " << info << " du nouveau contact"<< " : ";
		if (!std::getline(std::cin, str))
			exit(-1);
		if (!isEmpty(str))
			break ;
		else
		{
			std::cout << "L''information doit etre composee d'au moins un carcatere alphanumerique" << std::endl;
			std::cout << "Reessayez !" << std::endl;
		}
	}
}

// Display Contact's info for PhoneBook tab
void	Contact::displayContactSearch() const
{
	PhoneBook::displayResizedStr(m_first_name);
	std::cout << "|";
	PhoneBook::displayResizedStr(m_last_name);
	std::cout << "|";
	PhoneBook::displayResizedStr(m_nick_name);
}

void	Contact::displayContact() const
{
	std::cout << "Prenom : " << m_first_name << std::endl;
	std::cout << "Nom de famille : " << m_last_name << std::endl;
	std::cout << "Surnom : " << m_nick_name << std::endl;
	std::cout << "Numero de telephone : " << m_tel_number << std::endl;
	std::cout << "Plus lourd secret : " << m_darkest_secret << std::endl;
}
