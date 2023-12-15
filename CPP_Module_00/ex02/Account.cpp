/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:04 by clbernar          #+#    #+#             */
/*   Updated: 2023/12/15 19:09:38 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//awk '{ $1=""; print $0 }'
// Constructor by default
Account::Account()
{

	_accountIndex = _nbAccounts++;
	_amount = 0;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_displayTimestamp();
	std::cout<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}

// Surcharged constructor
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}

// Destructor
Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout<<" accounts:"<<getNbAccounts()<<";total:"<<getTotalAmount();
	std::cout<<";deposits:"<<getNbDeposits()<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"<<deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout<<";amount:"<<_amount<<";nb_deposits:"<<_nbDeposits<<std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:";
	if (checkAmount() < withdrawal)
	{
		std::cout<<"refused"<<std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout<<withdrawal<<";amount:"<<_amount<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
	return true;
}

int	Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:";
	std::cout<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<< std::endl;
}

void	Account::_displayTimestamp()
{
	// Obtenir l'heure courante
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);

	// Afficher le timestamp
	std::cout << "["
		<< now->tm_year + 1900 // L'année commence à partir de 1900
		<< std::setfill('0') << std::setw(2) << now->tm_mon + 1 // Le mois commence à partir de 0
		<< std::setfill('0') << std::setw(2) << now->tm_mday // Jour du mois
		<< "_"
		<< std::setfill('0') << std::setw(2) << now->tm_hour // Heures
		<< std::setfill('0') << std::setw(2) << now->tm_min  // Minutes
		<< std::setfill('0') << std::setw(2) << now->tm_sec  // Secondes
		<< "]";
}
