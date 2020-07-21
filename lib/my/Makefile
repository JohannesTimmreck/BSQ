##
## EPITECH PROJECT, 2018
## first makefile
## File description:
## myfirst makefile
##

NAME	=	libmy.a

SRC	=	my_getnbr.c	\

OBJ	=	$(SRC:.c=.o)

lib:	$(OBJ)
	ar rc libmy.a $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean lib
