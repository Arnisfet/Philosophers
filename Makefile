SRC	=	$(addprefix ./src/, actions.c	another.c	main.c	threads.c)

OBJ	=	$(SRC:.c=.o)

WWW	=	-Wall -Werror -Wextra

INC_LIB	=	-I libft

NAME	=	philo


all: $(NAME)

echo:
	@echo "\n\t\t\t\t\033[0mMaking project!\n"

$(NAME): echo	$(OBJ)
	@echo "\n\n"
	@echo "\t\t\t\tCompile LIBFT!\n"
	@make -C libft
	@echo "\t\t\t\tLibft is ready!\n"
	@gcc $(OBJ) -pthread libft/libft.a -g -o $(NAME)
	@echo "\t\t\t\033[0mProject is ready! Launch philo.exe.\n"

%.o:	%.c
	@gcc -c -g -I. $(INC_LIB) $(WWW) $< -o $@
	@echo "\t\033[0mCompile $@"
clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@echo "\t\t\t\t\033[32mDelete all philo obj" 
	@rm -rf $(NAME) 

re: fclean all
