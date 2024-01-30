/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:12:51 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/30 14:34:06 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE__HPP
#define __BITCOINEXCHANGE__HPP

#include <string>

class BitcoinExchange
{
	public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& asign);
	~BitcoinExchange();

	BitcoinExchange & operator=(BitcoinExchange const& equal);

	private:
	std::map<std::string, double>	m_exchange;

};

#endif
