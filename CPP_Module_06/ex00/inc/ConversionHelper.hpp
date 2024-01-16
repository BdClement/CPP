/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionHelper.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:43:10 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/16 19:53:40 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONVERSIONHELPER__HPP
#define __CONVERSIONHELPER__HPP

#include <string>
#include <sstream>
#include <iostream>

class ConversionHelper
{
	public:
	ConversionHelper();
	ConversionHelper(ConversionHelper const& asign);
	~ConversionHelper();

	// Getters
	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble()const;
	std::string	getCharError() const;
	std::string	getIntError() const;
	std::string	getFloatError() const;
	std::string	getDoubleError() const;

	ConversionHelper & operator=(ConversionHelper const& equal);

	void	charConversion(std::string to_convert);
	void	intConversion(std::string to_convert);
	void	floatConversion(std::string to_convert);
	void	doubleConversion(std::string to_convert);
	void	unknownConversion();
	void	display() const;
	void	displayCharConversion() const;
	void	displayIntConversion() const;
	void	displayFloatConversion() const;
	void	displayDoubleConversion() const;

	private:
	char		m_char;
	int			m_int;
	float		m_float;
	double		m_double;
	std::string	m_char_error;
	std::string	m_int_error;
	std::string	m_float_error;
	std::string	m_double_error;
};
#endif
