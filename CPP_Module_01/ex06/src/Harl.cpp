/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:23:46 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/14 19:49:25 by Enfoirax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

const std::string stringTab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

// Constructor
Harl::Harl()
{

}

// Destructor 
Harl::~Harl()
{
	
}

void    Harl::complain(std::string level)
{
	// Declaration d'un tableau de pointeur sur fonction
	void (Harl::*functionPointer[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	// Recherche de l'index correspondant a l'argument
	int	i(0);
	while (i < 4)
	{
		if (stringTab[i] == level)
			break ;
		i++;
	}
    // Affichage du niveau
    if (i < 4)
        std::cout<<"[ "<<level<<" ]"<<std::endl;
    // Execution des ou de la fonction
     switch (i + 1) {
        case 1:
            for (int i = 0; i < 4; i++)
                (this->*functionPointer[i])();
            break;
        case 2:
            for (int i = 1; i < 4; i++)
                (this->*functionPointer[i])();
            break;
        case 3:
            for (int i = 2; i < 4; i++)
                (this->*functionPointer[i])();
            break;
        case 4:
            for (int i = 3; i < 4; i++)
                (this->*functionPointer[i])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
} 

 void    Harl::debug(void)
 {
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"<<std::endl;
 }
void    Harl::info(void)
{
	std::cout<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" <<std::endl;
}

void    Harl::warning(void)
{
	std::cout<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<std::endl;
}

void    Harl::error(void)
{
	std::cout<< "This is unacceptable ! I want to speak to the manager now." <<std::endl;
}
