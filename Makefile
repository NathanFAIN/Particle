##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my makefile
##

NAME		=	binary

CC			=	gcc

CFLAGS		=	-I ./include/		\
				-W					\
				-Wextra				\
				-Wall				\

CSFMLFLAGS	=	-lcsfml-graphics	\
				-lcsfml-window		\
				-lcsfml-system		\
				-lm					\

SRC			=	src/main.c			\
				src/particle.c		\

OBJ			=	$(SRC:.c=.o)

all: 			$(NAME)

$(NAME): 		$(OBJ)
				$(CC) $(OBJ) $(CFLAGS) $(CSFMLFLAGS) -o $(NAME)

clean:
				rm -f $(OBJ)

fclean: 		clean
				rm -f $(NAME)

re: 			fclean all