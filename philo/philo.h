/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:36:02 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/27 18:26:48 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include	<sys/time.h>

# define PUT_FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3

struct	s_struct;

typedef struct s_philo_attribute
{
	pthread_t		arr_ph;
	int				flag;
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
	long int		philo;
	long int		time_to_born;
	long int		time_to_eat;
	long int		time_to_die;
	long int		time_to_sleep;
	long int		count_eat;
	int				death_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	death;
	pthread_mutex_t	eat;
	t_attribute		*philo_t;
}				t_data;

void		error_message(void);
long int	get_time(void);
int			threads(t_data *p, int number);
void		put_fork(t_attribute *p);
int			display_message(t_attribute *p, int number);
void		join_and_destroy(t_data *p);
void		fall_asleep(t_attribute *p);
void		eat(t_attribute *p);
void		*death_monitor(void *check);
void		my_usleep(long int value);

#endif
