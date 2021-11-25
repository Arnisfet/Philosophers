//
// Created by arnisfet on 22.11.2021.
//

#ifndef PHILOSOPHERS_PHILO_BONUS_H
#define PHILOSOPHERS_PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_philo_attribute
{
	int				pid;
	long int		time_to_born_ph;
	int				number;
	int				left_fork;
	int				right_fork;
	long int		limit;
	long int		last_eat;
	int				eating;
	long int		count_eat_ph;
	struct s_struct	*data;
}				t_attribute;

typedef struct s_struct
{
	long int		forks;
	long int		time_to_born;
	long int		time_to_eat;
	long int		time_to_die;
	long int		time_to_sleep;
	long int		count_eat;
	int				death_flag;
	t_attribute		*forks_t;

	sem_t			*write;
	sem_t			*death;
	sem_t			*forks_n;
}				t_data;

void	error_parse(char **av, int ac, t_data *p);
void	forks(t_data *p, int number);
void	error_message(void);

#endif //PHILOSOPHERS_PHILO_BONUS_H
