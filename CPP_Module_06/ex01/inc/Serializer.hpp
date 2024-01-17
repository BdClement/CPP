/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:30:39 by clbernar          #+#    #+#             */
/*   Updated: 2024/01/17 19:56:20 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER__HPP
#define __SERIALIZER__HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	private:
	Serializer();
	Serializer(Serializer const& asign);
	Serializer & operator=(Serializer const& equal);
};

#endif
