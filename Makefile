##
## EPITECH PROJECT, 2018
##
## File description:
## Makefile
##


CFLAGS = -Wall -Werror -Wextra -Iinc

LDFLAGS += -L ./lib -Wl,-rpath,./lib -lriceferee -lpthread

SRC	=	src/main.c	\
		src/thread.c \
		src/option.c \
		src/util.c	\
		src/handler.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	philo

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all