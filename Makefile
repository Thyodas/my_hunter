##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = my_hunter

INCLUDE = include

LIB = lib/my

CFLAGS = -I$(INCLUDE) -L$(LIB) -lmy -Wall -Wextra -g -W -Wall -Wextra\
		 -lcsfml-system -lcsfml-audio -lcsfml-window -lcsfml-graphics -lm

all: $(NAME)

make_lib:
		  make -C $(LIB)

$(NAME): make_lib $(OBJ)
		 gcc -o $(NAME) $(OBJ) $(CFLAGS)
		 rm -f $(OBJ)

clean:
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean $(NAME)