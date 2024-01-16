/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionHelper.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:49:04 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/16 19:50:19 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConversionHelper.hpp"

ConversionHelper::ConversionHelper() : m_char(0), m_int(0), m_float(0), m_double(0){}

ConversionHelper::ConversionHelper(ConversionHelper const& asign){*this = asign;}

ConversionHelper::~ConversionHelper(){}

ConversionHelper& ConversionHelper::operator=(ConversionHelper const & equal)
{
	if (*this != equal)
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

void	ConversionHelper::charConversion(std::string to_convert)
{
	m_char = to_convert[0];
	m_int = static_cast<int>(m_char);
	m_float = static_cast<float>(m_char);
	m_double = static_cast<double>(m_char);
}

void	ConversionHelper::intConversion(std::string to_convert)
{
	try
	{
		m_int = std::stoi(to_convert.c_str());
		m_float = static_cast<float>(m_int);
		m_double = static_cast<double>(m_int);
		// Gestion du depassement ??
		m_char = static_cast<char>(m_int);
	}
	catch (const std::invalid_argument& e) // A CHECKER
	{
		m_int_error = e.what();
		m_char_error = "Impossible";
		m_float_error = "Impossible";
		m_double_error = "Impossible";
	}
	catch (const std::out_of_range& e)
	{
		m_int_error = e.what();
		m_char_error = "Impossible";
		m_float_error = "Impossible";
		m_double_error = "Impossible";
	}
}

void	ConversionHelper::floatConversion(std::string to_convert)
{
	try
	{
		m_float = std::stof(to_convert);
		m_double = static_cast<double>(m_float);
		m_int = static_cast<int>(m_float);
		// Gestion du depassement ??
		m_char = static_cast<char>(m_float);
	}
	catch(const std::invalid_argument& e)
	{
		error = e.what();
		m_char_error = "Impossible";
		m_float_error = "Impossible";
		m_double_error = "Impossible";
	}
	catch(const std::out_of_range& e)
	{
		error = e.what();
		m_char_error = "Impossible";
		m_float_error = "Impossible";
		m_double_error = "Impossible";
	}
}

void	ConversionHelper::doubleConversion(std::string to_convert)
{
	try
	{
		m_double = std::stod(to_convert);
		m_float = static_cast<float>(doubleValue);
		m_int = static_cast<int>(doubleValue);
		// Gestion du depassement ??
		m_char = static_cast<char>(doubleValue);
	}
	catch(const std::invalid_argument& e)
	{
		m_double_error = e.what();
	}
	catch(const std::out_of_range& e)
	{
		m_double_error = e.what();
	}
}

void	unknownConversion()
{
	m_char_error = "Impossible";
	m_int_error = "Impossible";
	m_float_error = "nanf";
	m_double_error = "nan";
}

void	ConversionHelper::display() const
{
	this->displayCharConversion();
	this->displayIntConversion();
	this->displayFloatConversion();
	this->displaydoubleConversion();
}

void	ConversionHelper::displayCharConversion() const
{
	if (m_char_error.size() != 0)
		std::cout<<"char: "<<m_char_error<<std::endl;
	else if (isprint(m_char))
		std::cout<<"char: "<<m_char<<std::endl;
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
		std::cout<<"float: "<<m_float<<std::endl;
}

void	ConversionHelper::displaydoubleConversion() const
{
	if (m_double_error.size() != 0)
		std::cout<<"double: "<<m_double_error<<std::endl;
	else
		std::cout<<"double: "<<m_double<<std::endl;
}
