/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:15:21 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/03 12:44:38 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG__HPP
#define __DOG__HPP

#include "Animal.hpp"
#include "Brain.hpp"
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
    void		    affectIdeas(std::string const to_affect, int index);
    std::string	    getIdeas(int index) const;

    private:
    Brain   *m_brain;
};

#endif
