/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:36:02 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/15 17:41:48 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MY_PHILO_PHILO_H
# define MY_PHILO_PHILO_H

#include <string.h>
#include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include	<sys/time.h>

# define PUT_FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3

struct s_struct;

typedef struct s_philo_attribute
{
	pthread_t	arr_ph;
	int			number;
	long int	time_to_born;
	int			left_fork;
	int			right_fork;
	long int	limit;
	long int	last_eat;
	int			eating;
	long int	count_eat_ph;

	struct s_struct	*data;
}				t_attribute;

typedef struct s_struct
{
	long int	philo;
	long int	time_to_eat;
	long int	time_to_die;
	long int	time_to_sleep;
	long int	count_eat;
	int			death_flag;

	pthread_mutex_t *forks;
	pthread_mutex_t write;

	t_attribute *philo_t;
}				t_data;

void		error_message();
long int	get_time();
int 		threads(t_data *p, int number);
void		put_fork(t_attribute *p);
int			display_message(t_attribute *p, int number);
void		join_and_destroy(t_data *p);
void		fall_asleep(t_attribute *p);
void		eat(t_attribute *p);
void		*death_monitor(void *check);
void		my_usleep(long int value);

#endif //MY_PHILO_PHILO_H
