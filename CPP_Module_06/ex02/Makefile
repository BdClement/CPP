## MAIN VARIABLES

NAME =			a.out

CC = 			c++

CFLAGS = 		-Wall -Wextra -Werror -std=c++98

RM =			rm -f

RM_RF =			rm -rf

## SOURCES AND LIBS

SRC_DIR = 		./src

SRCS =			$(SRC_DIR)/main.cpp\
				$(SRC_DIR)/Base.cpp\
				# $(SRC_DIR)/A.cpp\
				# $(SRC_DIR)/B.cpp\
				# $(SRC_DIR)/C.cpp\

## OBJECTS

OBJ_DIR =		./obj

OBJS = 			$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

## HEADERS

HDIR = 			./inc

HD = 			$(HDIR)/Base.hpp\
				# $(HDIR)/A.hpp\
				# $(HDIR)/B.hpp\
				# $(HDIR)/C.hpp\


INC_HD =		-I $(HDIR)

## RULES

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS):		$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp $(HD)
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INC_HD) -c $< -o $@

clean:
				$(RM_RF) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean fclean re
