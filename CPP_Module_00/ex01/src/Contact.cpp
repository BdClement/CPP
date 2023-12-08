/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:47 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/08 19:31:20 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.hpp"
#include "Contact.hpp"

// Constructeur par defaut
Contact::Contact()
{

}

void	Contact::setContact()
{
	std::cout << "Entrez le prenom du nouveau contact : ";
	std::getline(std::cin, m_first_name);
	std::cout << "Entrez le nom de famille du nouveau contact : ";
	std::getline(std::cin, m_last_name);
	std::cout << "Entrez le surnom du nouveau contact : ";
	std::getline(std::cin, m_nick_name);
	std::cout << "Entrez le numero de telephone du nouveau contact : ";
	std::getline(std::cin, m_tel_number);
	std::cout << "Entrez le plus lourd secret du nouveau contact : ";
	std::getline(std::cin, m_darkest_secret);

}

void	Contact::displayPart() const
{
	displayResizedStr(m_first_name);
	std::cout << "|";
	displayResizedStr(m_last_name);
	std::cout << "|";
	displayResizedStr(m_nick_name);
	// std::cout << m_first_name << "|";
	// std::cout << m_last_name << "|";
	// std::cout << m_nick_name;
}

void	Contact::displayFull() const// a ameliorer
{
	std::cout << "Le contact s'appelle : " << m_first_name << " " << m_last_name << std::endl;
	std::cout << "Son surnom est : " << m_nick_name << std::endl;
	std::cout << "Son numero de telephone est : " << m_tel_number << std::endl;
	std::cout << "Et son plus lourd secret est : " << m_darkest_secret << std::endl;
}

// void	Contact::displayResizedAttr(std::string resize);
// {
// 	if(resize.size() > 10)
// 	{
// 		resize.resize(9);
// 		resize.insert(9, ".");
// 	}
// 	else if(resize.size() < 10)
// 	{
// 		while (resize.size() != 10)
// 			resize.insert(0, " ");
// 	}
// }
