/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:33:07 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/12 17:16:40 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string& stringREF = str;

    // Address
    std::cout<< &str <<std::endl;
    std::cout<< stringPTR <<std::endl;
    std::cout<< &stringREF <<std::endl;

    // Value
    std::cout<< str <<std::endl;
    std::cout<< *stringPTR <<std::endl;
    std::cout<< stringREF <<std::endl;
    return 0;
}
