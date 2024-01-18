/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:10:00 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/18 18:18:45 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE__HPP
#define __BASE__HPP

#include <iostream>

class Base
{
    public:
    virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
