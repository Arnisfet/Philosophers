SRC	=	$(addprefix ./src/, actions.c	another.c	main.c	threads.c)

OBJ	=	$(SRC:.c=.o)

WWW	=	-Wall -Werror -Wextra

NAME	=	philo


all: $(NAME)

echo:
	@echo "\n\t\t\t\t\033[0mMaking project!\n"

$(NAME): echo	$(OBJ) philo.h
	@gcc $(OBJ) -pthread -g -o $(NAME)
	@echo "\t\t\t\033[0mProject is ready! Launch philo\n"

%.o:	%.c
	@gcc -c -g -I. $(WWW) $< -o $@
	@echo "\t\033[0mCompile $@"
clean:
	@rm -f $(OBJ)
	@echo "\t\t\t\t\033[32mDelete all philo obj\n"

fclean: clean
	@echo "\t\t\t\t\033[32mDelete philo binary\n"
	@rm -rf $(NAME) 

re: fclean all
