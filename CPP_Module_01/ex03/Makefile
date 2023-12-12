## MAIN VARIABLES

NAME =			violence

CC = 			c++

CFLAGS = 		-Wall -Wextra -Werror -std=c++98

RM =			rm -f

RM_RF =			rm -rf

## SOURCES AND LIBS

SRC_DIR = 		./src

SRCS =			$(SRC_DIR)/main.cpp\
				$(SRC_DIR)/Weapon.cpp\
				$(SRC_DIR)/HumanA.cpp\
				$(SRC_DIR)/HumanB.cpp\

## OBJECTS

OBJ_DIR =		./obj

OBJS = 			$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

## HEADERS

HDIR = 			./inc

HD = 			$(HDIR)/HumanA.hpp\
				$(HDIR)/HumanB.hpp\
				$(HDIR)/Weapon.hpp\

INC_HD =		-I $(HDIR)

## RULES

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(INC_HD) $(OBJS) -o $@

$(OBJS):		$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp $(HD)
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INC_HD) -c $< -o $@

clean:
				$(RM_RF) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean fclean re
