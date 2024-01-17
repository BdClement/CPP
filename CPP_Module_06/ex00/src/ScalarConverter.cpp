/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:49:49 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/17 18:18:45 by clbernar         ###   ########.fr       */
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

	if (conversion.isChar(to_convert))
	{
		conversion.charConversion(to_convert);
	}
	else if (conversion.isInt(to_convert))
	{
		conversion.intConversion();
	}
	else if( conversion.isFloat(to_convert))
	{
		conversion.floatConversion();
	}
	else if (conversion.isDouble(to_convert))
	{
		conversion.doubleConversion();
	}
	else
	{
		conversion.unknownConversion();
	}
	conversion.display();
}
