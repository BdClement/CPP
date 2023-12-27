/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:13:26 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/26 20:27:01 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT__HPP
#define __WRONGCAT__HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    // WrongCat(std::string type);
    WrongCat(WrongCat const& asign);
    virtual ~WrongCat();

    WrongCat & operator=(WrongCat const & equal);
    void    makeSound() const;

    private:
};

#endif
