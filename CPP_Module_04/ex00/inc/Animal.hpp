/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:02:10 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:19:16 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL__HPP
#define __ANIMAL__HPP

#include <string>
#include <iostream>

class Animal
{
    public:
    Animal();
    Animal(std::string type);
    Animal(Animal const& asign);
    virtual ~Animal();

    Animal & operator=(Animal const & equal);
    const std::string& getType() const;
    virtual void    makeSound() const;

    protected:
    std::string m_type;
};

std::ostream &  operator<<(std::ostream & output, Animal const & input);

#endif 
