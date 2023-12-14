/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:07:27 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/14 19:22:13 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

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
