/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:19:33 by Enfoirax          #+#    #+#             */
/*   Updated: 2024/01/03 12:44:28 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT__HPP
#define __CAT__HPP

#include "Animal.hpp"
#include "Brain.hpp"
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
    void		    affectIdeas(std::string const to_affect, int index);
    std::string	    getIdeas(int index) const;

    private:
    Brain  *m_brain;
};

#endif
