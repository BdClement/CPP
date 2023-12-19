/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:37 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/19 21:59:56 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__HPP
#define __FIXED__HPP

#include <iostream>

class Fixed
{
    public:
    Fixed();
    Fixed(Fixed const & asign);
    ~Fixed();

    Fixed & operator=(Fixed const & equal);
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    private:
    int                 m_value;
    int const static    m_frac_part;
        
};

#endif
