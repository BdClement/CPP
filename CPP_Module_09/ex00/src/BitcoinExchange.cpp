/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:34:45 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/31 14:30:15 by clbernar         ###   ########.fr       */
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
			double price = std::strtod(price_str.c_str(), NULL);
			m_data_base.insert(std::pair<std::string, double>(date, price));
		}
		ifs.close();
	}
	catch (const std::exception& )
	{
		std::cerr<<"Data_base file couldn't be opened"<<std::endl;
		exit(EXIT_FAILURE);
	}
}

void	BitcoinExchange::run_exchange(std::string line)
{
	// Check pipe
	if (line.find("|") == std::string::npos)
	{
		std::cout<<"Error : bad input => "<<line<<std::endl;
		return ;
	}
	// Split date and value and clean strings from space
	std::size_t	pos = line.find("|");
	std::string date = line.substr(0, pos);
	std::string	value = line.substr(pos + 1);
	this->clean_string(date);
	this->clean_string(value);
	// Check date and value format
	if (!this->check_date(date) || !check_value(value))
		return ;
	// Result
	this->calcul_result(date, value);
}

void	BitcoinExchange::calcul_result(std::string date, std::string value)
{
	double	value_double = std::strtod(value.c_str(), NULL);
	std::map<std::string, double>::iterator it = m_data_base.find(date);
	if (it != m_data_base.end())
		std::cout<<date<<" => "<<value<<" = "<<value_double * it->second<<std::endl;
	else
	{
		std::map<std::string, double>::const_iterator it2 = m_data_base.begin();
		if (it2->first > date)
		{
			std::cout<<"Bitcoin wasn't born at this period"<<std::endl;
			return ;
		}
		while (it2 != m_data_base.end() && it2->first < date)
			++it2;
		--it2;
		std::cout<<date<<" => "<<value<<" = ";
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout<<value_double * it2->second<<std::endl;
	}
}

bool	BitcoinExchange::check_value(std::string value)
{
	char	*end;
	double	value_double = std::strtod(value.c_str(), &end);
	if (*end != '\0' )
	{
		std::cout<<"Error : bad value format => "<<value<<std::endl;
		return false;
	}
	else if (value_double < 0)
	{
		std::cout<<"Error : not a positive number."<<std::endl;
		return false;
	}
	else if (value_double > 1000)
	{
		std::cout<<"Error : too large number."<<std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::check_date(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout<<"Error : bad date format => "<<date<<std::endl;
		return false;
	}
    // Split each part and convert them in long int
	char *endptr_year, *endptr_month, *endptr_day;
	long int year = strtol(date.substr(0, 4).c_str(), &endptr_year, 10);
	long int month = strtol(date.substr(5, 2).c_str(), &endptr_month, 10);
	long int day = strtol(date.substr(8, 2).c_str(), &endptr_day, 10);
	if (*endptr_year != '\0' || *endptr_month != '\0' || *endptr_day != '\0')
	{
		std::cout<<"Error : bad date format => "<<date<<std::endl;
		return false;
	}
	if (!(year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31))
		std::cout<<"Error : bad date format => "<<date<<std::endl;
    return (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
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

// Fonction Test
// void	BitcoinExchange::display_map() const
// {
// 	std::map<std::string, double>::const_iterator it;
// 	for(it = m_data_base.begin(); it != m_data_base.end(); ++it)
// 	{
// 		std::cout<<it->first<<"||";
// 		std::cout << std::fixed;
// 		std::cout.precision(2);
// 		std::cout<<it->second<<std::endl;
// 	}
// }
