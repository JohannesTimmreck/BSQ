##
## EPITECH PROJECT, 2018
## my Makefile
## File description:
## 
##

SRC	=	main.c	\
		create_grid_array.c	\
		find_biggest_square.c	\

NAME	=	bsq

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-g

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	make -C lib/my_printf
	$(CC) -o $(NAME) $(OBJ) -I include/ -L lib -l printf -L lib -l my -W -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)
	make clean -C lib/my
	make clean -C lib/my_printf

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my
	make fclean -C lib/my_printf

re: fclean all
