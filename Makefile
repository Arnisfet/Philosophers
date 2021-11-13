SRC	=	$(addprefix ./src/, actions.c	another.c	main.c	threads.c)

OBJ	=	$(SRC:.c=.o)

WWW	=	-Wall -Werror -Wextra

INC_LIB	=	-I libft/libft.h

NAME	=	philo

%.o:	%.c
	gcc -c -I. $(INC_LIB) $< -o $@
	

all:	$(OBJ)
	make -C libft
	gcc $(OBJ) -pthread libft/libft.a -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME) 

re: fclean all
