##
## EPITECH PROJECT, 2018
##
## File description:
## Makefile
##


CFLAGS = -Wall -Werror -Wextra -Iinc

LDFLAGS += -Llib -lriceferee -lpthread

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	philo

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all