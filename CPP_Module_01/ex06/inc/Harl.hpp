/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:51:11 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/14 19:22:57 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP
#define __HARL_HPP

#include <string>

class Harl
{
    public:
    Harl();
    ~Harl();

    void    complain(std::string level);

    private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

};

#endif
