/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:34:45 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/30 20:01:40 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->fill_map();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& asign)
{
	std::map<std::string, double>::const_iterator it;
	for(it = asign.m_data_base.begin(); it != asign.m_data_base.end(); ++it)
		m_data_base.insert(*it);
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & equal)
{
	if (this != &equal)
	{
		m_data_base.clear();
		std::map<std::string, double>::const_iterator it;
		for(it = equal.m_data_base.begin(); it != equal.m_data_base.end(); ++it)
			m_data_base.insert(*it);
	}
	return *this;
}

void	BitcoinExchange::fill_map()
{
	std::ifstream	ifs("data.csv", std::ifstream::in);
	try
	{
		if (!ifs.is_open())
			throw std::exception();
		std::string	line;
		std::getline(ifs, line);
		while (std::getline(ifs, line))
		{
			std::size_t	pos = line.find(",");
			std::string date = line.substr(0, pos);
			std::string	price_str = line.substr(pos + 1);
			double price = std::strtod(price_str.c_str(), NULL);// Perte de precision : obligatoire ?
			m_data_base.insert(std::pair<std::string, double>(date, price));
			// std::cout<<date<<"||||"<<price<<"|||||||||||"<<price2<<std::endl;
		}
		ifs.close();
	}
	catch (const std::exception& )
	{
		std::cerr<<"Data_base file couldn't be opened"<<std::endl;
		exit(EXIT_FAILURE);
	}
}

void	BitcoinExchange::display_map() const
{
	std::map<std::string, double>::const_iterator it;
	for(it = m_data_base.begin(); it != m_data_base.end(); ++it)
	{
		std::cout<<it->first<<"||";
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout<<it->second<<std::endl;
	}
}

void	BitcoinExchange::run_exchange(std::string line)
{
	// Parsing
	// Message d'erreur ou resultat
	if (line.find("|") == std::string::npos) // FFonction ?
	{
		std::cout<<"bad input => "<<line<<std::endl;
		return ;
	}
	std::size_t	pos = line.find("|");
	std::string date = line.substr(0, pos);
	std::string	value = line.substr(pos + 1);
	this->clean_string(date);
	this->clean_string(value);
	std::cout<<date<<"|"<<value<<std::endl;
	this->check_date(date);
	// check date
	// check nombre
}

bool	BitcoinExchange::check_date(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout<<"Error : bad date format => "<<date<<std::endl;
		return false;
	}
    // Convertir les parties de la date en entiers
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    // Vérifier les valeurs converties
	if (!(year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31))
		std::cout<<"Error : bad date format => "<<date<<std::endl;
    return (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31);// CHECK v dans test.txt
}

void	BitcoinExchange::clean_string(std::string &line)
{
	std::string	result;
	bool	spaceAllowed = false;
	for (std::size_t i = 0; i < line.size(); ++i)
	{
		if (line[i] == ' ')
		{
			if (spaceAllowed)
			{
				result += ' ';
				spaceAllowed = false;
			}
		}
		else
		{
			result += line[i];
			spaceAllowed = true;
		}
	}
	while (result[result.size() -1] == ' ')
		result.resize(result.size() - 1);
	line = result;
}


// bool	BitcoinExchange::check_format(std::string line)
// {
// 	if (line.find("|") == std::string::npos)
// 	{
// 		std::cout<<"bad input => "<<line<<std::endl;
// 		return false;
// 	}
// 	try
// 	{
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cout<<e.what()<<std::endl;
// 		return false;
// 	}
// 	return true;
// }
