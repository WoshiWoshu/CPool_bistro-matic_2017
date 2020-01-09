##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc -g3 -Wall -Wextra

FLAG	=	-I /include

RM	=	rm -f

SRC	=	./eval_expr/shunting_yard_algorithm/shunting_yard_algorithm.c		\
		./eval_expr/shunting_yard_algorithm/verified_token_and_process.c	\
		./eval_expr/bistro_preliminary.c					\
		./eval_expr/eval_expr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(MAKE) -C ./libmy
	$(CC) $(OBJ) -o $(NAME) -L ./libmy -l my

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	make -C libmy fclean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all fclean clean re
