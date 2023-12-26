/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:19:33 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:19:21 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT__HPP
#define __CAT__HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
    public:
    Cat();
    // Cat(std::string type);
    Cat(Cat const& asign);
    virtual ~Cat();

    Cat & operator=(Cat const & equal);
    virtual void    makeSound() const;

    private:
};

#endif
