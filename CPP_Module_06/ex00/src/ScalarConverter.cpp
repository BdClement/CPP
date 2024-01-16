/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:49:49 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/16 20:04:22 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ConversionHelper.hpp"
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const& asign){ *this = asign;}

ScalarConverter::~ScalarConverter(){}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & equal){(void)equal; return *this;}

void ScalarConverter::convert(std::string to_convert)
{
	ConversionHelper conversion;

	if (isChar(to_convert))
	{
		conversion.charConversion(to_convert);
	}
	else if (isInt(to_convert))
	{
		conversion.intConversion(to_convert);
	}
	else if( isFloat(to_convert))
	{
		conversion.floatConversion(to_convert);
	}
	else if (isDouble(to_convert))
	{
		conversion.doubleConversion(to_convert);
	}
	else
	{
		conversion.unknownConversion();
	}
	conversion.display();
}

bool	isChar(std::string to_convert)
{
	return to_convert.size() == 1 && !isdigit(to_convert[0]);
}

bool	isInt(std::string to_convert)
{
	// Utilisation de std::isstreamstring pour tenter de faire la conversion
	std::isstreamstring	iss(to_convert);

	int		value;
	char	remaining;
	// On fait la conversion vers l'int grace a >>, reussite ou echec
	bool conversionSuccess = (iss >> value);
	// On fait ensuite la conversion vers char pour capturer le char suivant
	// Si il restait des char cela signifie que tout n'a pas ete converti
	bool	noRemaining = (iss >> remaining);

	return conversionSuccess && !noRemaining;
}

bool	isFloat(std::string to_convert)
{
	// Utilisation de std::isstreamstring pour tenter de faire la conversion
	std::isstreamstring	iss(to_convert);

	float		value;
	char	remaining;
	// On fait la conversion vers l'float grace a >>, reussite ou echec
	bool conversionSuccess = (iss >> value);
	// On fait ensuite la conversion vers char pour capturer le char suivant
	// Si il restait des char cela signifie que tout n'a pas ete converti
	bool	noRemaining = (iss >> remaining);

	return conversionSuccess && !noRemaining;
}

bool	isDouble(std::string to_convert)
{
		// Utilisation de std::isstreamstring pour tenter de faire la conversion
	std::isstreamstring	iss(to_convert);
	// Declaration d'un double et d'un char
	double		value;
	char	remaining;
	// On fait la conversion vers l'double grace a >>, reussite ou echec
	bool conversionSuccess = (iss >> value);
	// On fait ensuite la conversion vers char pour capturer le char suivant
	// Si il restait des char cela signifie que tout n'a pas ete converti
	bool	noRemaining = (iss >> remaining);

	return conversionSuccess && !noRemaining;
}
