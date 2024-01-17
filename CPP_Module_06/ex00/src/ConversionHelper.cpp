/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionHelper.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:49:04 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/17 18:22:04 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConversionHelper.hpp"
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <limits>

ConversionHelper::ConversionHelper() : m_char(0), m_int(0), m_float(0), m_double(0){}

ConversionHelper::ConversionHelper(ConversionHelper const& asign){*this = asign;}

ConversionHelper::~ConversionHelper(){}

ConversionHelper& ConversionHelper::operator=(ConversionHelper const & equal)
{
	if (this != &equal)
	{
		m_char = equal.getChar();
		m_int = equal.getInt();
		m_float = equal.getFloat();
		m_double = equal.getDouble();
		m_char_error = equal.getCharError();
		m_int_error = equal.getIntError();
		m_float_error = equal.getFloatError();
		m_double_error = equal.getDoubleError();
	}
	return *this;
}

// Getters
char	ConversionHelper::getChar() const {return m_char;}
int		ConversionHelper::getInt() const {return m_int;}
float	ConversionHelper::getFloat() const {return m_float;}
double	ConversionHelper::getDouble()const {return m_double;}
std::string	ConversionHelper::getCharError() const {return m_char_error;}
std::string	ConversionHelper::getIntError() const {return m_int_error;}
std::string	ConversionHelper::getFloatError() const {return m_float_error;}
std::string	ConversionHelper::getDoubleError() const {return m_double_error;}

// FONCTIONS QUI DETERMINENT DE QUEL TYPE EST LA VALEUR LITTERALE
bool	ConversionHelper::isChar(std::string to_convert)
{
	return to_convert.size() == 1 && !isdigit(to_convert[0]);
}

bool	ConversionHelper::isInt(std::string to_convert)
{
	// check only digits or + / - at start so to_convert can be interpreted like an int
	if (to_convert.size() == 0)
		return false;
	size_t	i = 0;
	if (to_convert[0] == '+' || to_convert[0] == '-')
		i++;
	for (; i < to_convert.size(); i++)
	{
		if (!isdigit(to_convert[i]))
			return false;
	}
	// check overflow
	char *endstring;
	long long int value = std::strtoll(to_convert.c_str(), &endstring, 10);
	if (*endstring == '\0' && value >= INT_MIN && value <= INT_MAX)
		m_int = value;
	else
	{
		m_int_error = "int overflow";
		m_char_error = "impossible";
		m_float_error = "impossible";
		m_double_error = "impossible";
	}
	return true;
}

bool	ConversionHelper::isFloat(std::string to_convert)
{
	// check cas particuliers
	if (to_convert == "-inff")
	{
		m_float = -std::numeric_limits<float>::infinity();
		m_char_error = "impossible";
		m_int_error = "impossible";
		return true;
	}
	else if(to_convert == "+inff")
	{
		m_float = std::numeric_limits<float>::infinity();
		m_char_error = "impossible";
		m_int_error = "impossible";
		return true;
	}
	// Utilisation de std::istringstream pour tenter de faire la conversion
	std::istringstream	iss(to_convert);

	float		value;
	char	remaining;
	// On fait la conversion vers l'float grace a >>, reussite ou echec
	bool conversionSuccess = (iss >> value);
	// On fait ensuite la conversion vers char pour capturer le char suivant
	// Si il restait des char cela signifie que tout n'a pas ete converti
	bool	noRemaining = (iss >> remaining);
	if (remaining == 'f')
		noRemaining = (iss >> remaining);
	else
		return false;
	if (conversionSuccess && !noRemaining)
	{
		m_float = value;
		// passer le nombre dans une string et compare les size avec to_convert
		// pour determiner si il ya perte de precision
		return true;
	}
	return false;
}

bool	ConversionHelper::isDouble(std::string to_convert)
{
	// check cas particuliers
	if (to_convert == "-inf")
	{
		m_double = -std::numeric_limits<double>::infinity();
		m_char_error = "impossible";
		m_int_error = "impossible";
		return true;
	}
	else if(to_convert == "+inf")
	{
		m_double = std::numeric_limits<double>::infinity();
		m_char_error = "impossible";
		m_int_error = "impossible";
		return true;
	}
	// // Utilisation de std::istringstream pour tenter de faire la conversion
	std::istringstream	iss(to_convert);
	// Declaration d'un double et d'un char
	double		value;
	char	remaining;
	// On fait la conversion vers l'double grace a >>, reussite ou echec
	bool conversionSuccess = (iss >> value);
	// On fait ensuite la conversion vers char pour capturer le char suivant
	// Si il restait des char cela signifie que tout n'a pas ete converti
	bool	noRemaining = (iss >> remaining);

	if (conversionSuccess && !noRemaining)
	{
		m_double = value;
		// passer le nombre dans une string et compare les size avec to_convert
		// pour determiner si il ya perte de precision
		return true;
	}
	return false;
}

// FONCTIONS QUI CONVERTISSENT LE TYPE LITTERAL TROUVE
void	ConversionHelper::charConversion(std::string to_convert)
{
	// std::cout<<"Is CHAR"<<std::endl;
	m_char = to_convert[0];
	m_int = static_cast<int>(m_char);
	m_float = static_cast<float>(m_char);
	m_double = static_cast<double>(m_char);
}

void	ConversionHelper::intConversion()
{
	// std::cout<<"is INT"<<std::endl;
	m_float = static_cast<float>(m_int); // perte de precision avec les valeurs proches de INTMIN/MAX
	m_double = static_cast<double>(m_int);
	if (m_int >= 0 && m_int <= 127)
		m_char = static_cast<char>(m_int);
	else
		m_char_error = "impossible";
}

void	ConversionHelper::floatConversion()
{
	// std::cout<<"isFLOAT"<<std::endl;
	m_double = static_cast<double>(m_float);
	m_int = static_cast<int>(m_float);
	if (m_int >= 0 && m_int <= 127)
		m_char = static_cast<char>(m_float);
	else
		m_char_error = "impossible";
}

void	ConversionHelper::doubleConversion()
{
	// std::cout<<"isDOUBLE"<<std::endl;
	m_float = static_cast<float>(m_double);
	m_int = static_cast<int>(m_double);
	if (m_int >= 0 && m_int <= 127)
		m_char = static_cast<char>(m_double);
	else
		m_char_error = "impossible";
}

void	ConversionHelper::unknownConversion()
{
	m_char_error = "Impossible";
	m_int_error = "Impossible";
	m_float_error = "nanf";
	m_double_error = "nan";
}

// FONCTIONS DISPLAY
void	ConversionHelper::display() const
{
	this->displayCharConversion();
	this->displayIntConversion();
	this->displayFloatConversion();
	this->displayDoubleConversion();
}

void	ConversionHelper::displayCharConversion() const
{
	if (m_char_error.size() != 0)
		std::cout<<"char: "<<m_char_error<<std::endl;
	else if (isprint(m_char))
		std::cout<<"char: '"<<m_char<<"'"<<std::endl;
	else
		std::cout<<"char: Non displayable"<<std::endl;
}

void	ConversionHelper::displayIntConversion() const
{
	if (m_int_error.size() != 0)
		std::cout<<"int: "<<m_int_error<<std::endl;
	else
		std::cout<<"int: "<<m_int<<std::endl;
}

void	ConversionHelper::displayFloatConversion() const
{
	if (m_float_error.size() != 0)
		std::cout<<"float: "<<m_float_error<<std::endl;
	else
	{
		if (m_float == std::floor(m_float))
			std::cout<<"float: "<<std::fixed<<std::setprecision(1)<<m_float<<"f"<<std::endl;
		else
		std::cout<<"float: "<<m_float<<"f"<<std::endl;
	}
}

void	ConversionHelper::displayDoubleConversion() const
{
	if (m_double_error.size() != 0)
		std::cout<<"double: "<<m_double_error<<std::endl;
	else
	{
		if (m_double == std::floor(m_double))
		{
			std::cout<<"double: "<<std::fixed<<std::setprecision(1)<<m_double<<std::endl;
		}
		else
			std::cout<<"double: "<<m_double<<std::endl;
	}
}

// // Gestion overflow double et float ??
// // check only double
	// if (to_convert.size() == 0)
	// 	return false;
	// size_t	i = 0;
	// int		dot = 0;
	// if (to_convert[0] == '+' || to_convert[0] == '-')
	// 	i++;
	// for (; i < to_convert.size(); i++)
	// {
	// 	if (!isdigit(to_convert[i]))
	// 	{
	// 		if (to_convert[i] == '.' && dot < 1)
	// 			dot++;
	// 		else
	// 			return false;
	// 	}
	// }
	// // check overflow
	// char *endstring;
	// long double	value = std::strtold(to_convert.c_str(), &endstring);
	// if (*endstring == '\0' && value >= DBL_MIN && value <= DBL_MAX)
	// 	m_double = value;
	// else
	// {
	// 	m_int_error = "impossible";
	// 	m_char_error = "impossible";
	// 	m_float_error = "impossible";
	// 	m_double_error = "double overflow";
	// }
	// return true;
