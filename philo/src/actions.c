/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:59:03 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/28 13:02:48 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_attribute *p)
{
	if (p->data->philo == 1)
		return ((void) 0);
	p->last_eat = get_time();
	p->limit = p->last_eat + p->data->time_to_die;
	if (p->data->death_flag != 1)
		display_message(p, 2);
	p->eating = 1;
	my_usleep(p->data->time_to_eat * 1000);
	++p->count_eat_ph;
	p->eating = 0;
}

void	put_fork(t_attribute *p)
{
	if (p->data->philo == 1)
	{
		display_message(p, 1);
		my_usleep(p->data->time_to_die * 1000);
		return ((void) 0);
	}
	if (pthread_mutex_lock(&p->data->forks[p->left_fork]) != 0)
		return ((void) 0);
	if (p->data->death_flag != 1)
		display_message(p, 1);
	if (pthread_mutex_lock(&p->data->forks[p->right_fork]) != 0)
		return ((void) 0);
	if (p->data->death_flag != 1)
		display_message(p, 1);
}

void	fall_asleep(t_attribute *p)
{
	if (p->data->philo == 1)
		return ((void) 0);
	display_message(p, 3);
	pthread_mutex_unlock(&p->data->forks[p->left_fork]);
	pthread_mutex_unlock(&p->data->forks[p->right_fork]);
	my_usleep(p->data->time_to_sleep * 1000);
}
