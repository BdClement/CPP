## MAIN VARIABLES

NAME =			test

CC = 			c++

CFLAGS = 		-Wall -Wextra -Werror -std=c++98

RM =			rm -f

RM_RF =			rm -rf

## SOURCES AND LIBS

SRCS =			Account.cpp\
				tests.cpp\

## OBJECTS

OBJS =			$(SRCS:.cpp=.o)

## HEADERS

INC =			Account.hpp\

## RULES

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:			%.cpp $(INC)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM_RF) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean fclean re
