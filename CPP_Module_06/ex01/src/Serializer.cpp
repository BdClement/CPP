/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:39:17 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/17 19:56:08 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer(){}
Serializer::Serializer(Serializer const& asign){ *this = asign;}
Serializer::~Serializer(){}
Serializer& Serializer::operator=(Serializer const & equal){(void)equal; return *this;}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
