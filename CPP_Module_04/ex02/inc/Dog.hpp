/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:15:21 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/27 16:55:12 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG__HPP
#define __DOG__HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
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
