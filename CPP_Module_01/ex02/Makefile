## MAIN VARIABLES

NAME =			test

CC = 			c++

CFLAGS = 		-Wall -Wextra -Werror -std=c++98

RM =			rm -f

RM_RF =			rm -rf

## SOURCES AND LIBS

SRCS =			main.cpp\

## OBJECTS

OBJS =			main.o

## HEADERS

## RULES

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS):		$(SRCS)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM_RF) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean fclean re
