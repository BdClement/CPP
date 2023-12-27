/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:08:45 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:27:08 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL__HPP
#define __WRONGANIMAL__HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
    WrongAnimal();
    // WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const& asign);
    virtual ~WrongAnimal();

    WrongAnimal & operator=(WrongAnimal const & equal);
    const std::string& getType() const;
    void    makeSound() const;

    protected:
    std::string m_type;
};

std::ostream &  operator<<(std::ostream & output, WrongAnimal const & input);

#endif 
