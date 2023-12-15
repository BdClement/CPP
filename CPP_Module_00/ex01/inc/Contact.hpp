/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:53:32 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/15 18:42:51 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

class	Contact
{
	// methodes
	public :
	Contact();

	void	setContact();
	void	getInfo(std::string &str, std::string info);
	void	displayContactSearch() const;
	void	displayContact() const;
	bool	isEmpty(std::string str) const;

	// attributs
	private :
	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nick_name;
	std::string	m_tel_number;
	std::string	m_darkest_secret;
};

#endif
