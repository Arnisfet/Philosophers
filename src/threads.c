/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:59:56 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/20 17:06:15 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_actions(void *check)
{
	t_attribute		*p;
	pthread_t		monitor;

	p = (t_attribute *)check;
	p->time_to_born_ph = p->data->time_to_born;
	p->last_eat = get_time();
	p->limit = p->last_eat + p->data->time_to_die;
	p->eating = 0;
	p->count_eat_ph = 0;
	if (pthread_create(&monitor, NULL, death_monitor, p) != 0)
		return ((void *)1);
	pthread_detach(monitor);
	while (p->data->death_flag != 1)
	{
		put_fork(p);
		eat(p);
		fall_asleep(p);
		if (p->data->death_flag != 1)
			display_message(p, 4);
	}
}

void	join_and_destroy(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->philo)
	{
		pthread_join(p->philo_t[i].arr_ph, NULL);
		i++;
	}
	i = 0;
	while (i < p->philo)
	{
		pthread_mutex_destroy(&p->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&p->death);
	pthread_mutex_destroy(&p->write);
}

int	threads(t_data *p, int number)
{
	int	i;

	i = 1;
	if (number == 2)
		i = 0;
	while (i < p->philo)
	{
		p->philo_t[i].number = i + 1;
		p->philo_t[i].data = p;
		p->philo_t[i].left_fork = i;
		p->philo_t[i].right_fork = ((i + 1) % p->philo);
		if (pthread_create(&p->philo_t[i].arr_ph, NULL, ft_actions,
				&(p->philo_t[i])) != 0)
			return (1);
		i += 2;
		my_usleep(1000);
	}
	return (0);
}

void	*death_monitor(void *check)
{
	t_attribute	*p;

	p = (t_attribute *)check;
	pthread_mutex_lock(&p->data->death);
	while (21)
	{
		if (p->count_eat_ph >= p->data->count_eat && p->data->count_eat
			!= 0 && p->data->death_flag != 1)
		{
			p->data->death_flag = 1;
			display_message(p, 6);
			return ((void *) 0);
		}
		if ((get_time() > p->limit) && !p->eating
			&& p->data->death_flag != 1)
		{
			p->data->death_flag = 1;
			display_message(p, 5);
			return ((void *) 0);
		}
	}
}
