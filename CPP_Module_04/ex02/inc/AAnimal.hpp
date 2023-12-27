/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:02:10 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/27 16:53:15 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL__HPP
#define __AANIMAL__HPP

#include <string>
#include <iostream>

class AAnimal
{
    public:
    AAnimal();
    AAnimal(std::string type);
    AAnimal(AAnimal const& asign);
    virtual ~AAnimal();

    AAnimal & operator=(AAnimal const & equal);
    const std::string& getType() const;
    // methode virtuelle pure
    virtual void    makeSound() const = 0;

    protected:
    std::string m_type;
};

std::ostream &  operator<<(std::ostream & output, AAnimal const & input);

#endif
