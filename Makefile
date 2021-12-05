##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = main.c \
	  src/all_loop.c \
	  src/check.c \
	  src/events.c \
	  src/memory.c \
	  src/music.c \
	  src/score.c \
	  src/utils.c \
	  src/sprites/background.c \
	  src/sprites/crosshair.c \
	  src/sprites/ennemy_utils.c \
	  src/sprites/ennemy.c \
	  src/sprites/planet.c \
	  src/sprites/projectile_utils.c \
	  src/sprites/projectile.c \
	  src/sprites/ship.c

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