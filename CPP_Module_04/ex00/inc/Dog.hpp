/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:15:21 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:19:23 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG__HPP
#define __DOG__HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
    public:
    Dog();
    // Dog(std::string type);
    Dog(Dog const& asign);
    virtual ~Dog();

    Dog & operator=(Dog const & equal);
    virtual void    makeSound() const;

    private:
};

#endif
