/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:12:51 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/30 19:51:40 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE__HPP
#define __BITCOINEXCHANGE__HPP

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
// #include <stdlib.h>
#include <ctime>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
	public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& asign);
	~BitcoinExchange();

	BitcoinExchange & operator=(BitcoinExchange const& equal);

	void	fill_map();
	void	display_map() const;
	void	run_exchange(std::string line);
	// bool	check_format(std::string line);
	void	clean_string(std::string &line);
	bool	check_date(std::string date);

	std::map<std::string, double>		m_data_base;
	private:
};

#endif
