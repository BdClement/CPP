/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Enfoirax <Enfoirax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:11:35 by Enfoirax          #+#    #+#             */
/*   Updated: 2023/12/14 18:26:42 by Enfoirax         ###   ########.fr       */
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
	// Execution de la fonction
	if (i < 4)
		(this->*functionPointer[i])();
	else
		std::cout<<"Harl is not configured for this. Sorry"<<std::endl;
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
// snippets class
// {
//     	"Class Declaration": {
// 			"prefix": "classmodele",
// 			"body": [
// 				"class ${1:nomADefinir}",
// 				"{",
// 				"    public:",
// 				"    // Méthodes de la classe",
// 				"    $1();",
// 				"    ~$1();",
// 				"",
// 				"    private:",
// 				"    // Attributs membres de la classe",
// 				"",
// 				"};"
// 			],
// 			"description": "Template for a C++ class declaration"
// 		}
// }


// Snippets Makefile
	// {
	// 	"Custom Makefile": {
	// 		"prefix": "makefile",
	// 		"body": [
	// 			"## MAIN VARIABLES",
	// 			"",
	// 			"NAME = \t\t\t",
	// 			"",
	// 			"CC = \t\t\tc++",
	// 			"",
	// 			"CFLAGS = \t\t-Wall -Wextra -Werror -std=c++98",
	// 			"",
	// 			"RM =\t\t\trm -f",
	// 			"",
	// 			"RM_RF =\t\t\trm -rf",
	// 			"",
	// 			"## SOURCES AND LIBS",
	// 			"",
	// 			"SRC_DIR = \t\t./src",
	// 			"",
	// 			"SRCS =\t\t\t${SRC_DIR}/",
	// 			"",
	// 			"## OBJECTS",
	// 			"",
	// 			"OBJ_DIR =\t\t./obj",
	// 			"",
	// 			"OBJS = \t\t\t${patsubst ${SRC_DIR}/%.cpp, ${OBJ_DIR}/%.o, ${SRCS}}",
	// 			"",
	// 			"## HEADERS",
	// 			"",
	// 			"HDIR = \t\t\t./inc",
	// 			"",
	// 			"HD = \t\t\t${HDIR}/",
	// 			"",
	// 			"INC_HD =\t\t-I ${HDIR}",
	// 			"",
	// 			"## RULES",
	// 			"",
	// 			"all:\t\t\t${NAME}",
	// 			"",
	// 			"${NAME}:\t\t${OBJS}",
	// 			"\t\t\t\t${CC} ${CFLAGS} ${INC_HD} ${OBJS} -o $@",
	// 			"",
	// 			"${OBJS}:\t\t${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${HD}",
	// 			"\t\t\t\tmkdir -p ${OBJ_DIR}",
	// 			"\t\t\t\t${CC} ${CFLAGS} ${INC_HD} -c $< -o $@",
	// 			"",
	// 			"clean:",
	// 			"\t\t\t\t${RM_RF} ${OBJ_DIR}",
	// 			"",
	// 			"fclean:\t\t\tclean",
	// 			"\t\t\t\t${RM} ${NAME}",
	// 			"",
	// 			"re:\t\t\t\tfclean all",
	// 			"",
	// 			".PHONY:\t\t\tall clean fclean re"
	// 		],
	// 		"description": "Custom Makefile Template"
	// 	}
	// }
