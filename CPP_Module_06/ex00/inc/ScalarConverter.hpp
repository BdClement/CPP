/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:25:44 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/16 19:52:26 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER__HPP
#define __SCALARCONVERTER__HPP

#include <string>
#include "ConversionHelper.hpp"

class ScalarConverter
{
	public:
	~ScalarConverter();


	static void convert(std::string to_convert);

	private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const& asign);
	ScalarConverter & operator=(ScalarConverter const& equal);

};

bool	isChar(std::string to_convert);
bool	isInt(std::string to_convert);
bool	isFloat(std::string to_convert);
bool	isDouble(std::string to_convert);

#endif
