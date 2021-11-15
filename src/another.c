/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:35:41 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/15 19:08:14 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_message(void)
{
	printf("Bad arg");
	exit (0);
}

long int	get_time(void)
{
	long int		result;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (result);
}

int display_message(t_attribute *p, int number)
{
	pthread_mutex_lock(&p->data->write);
	if (number == 1)
		printf("%ld %d has taken a fork\n", get_time() - p->time_to_born, p->number);
	if (number == 2)
		printf("%ld %d is eating\n", get_time() - p->time_to_born, p->number);
	if (number == 3 && p->data->death_flag != 1)
		printf("%ld %d is sleeping\n", get_time() - p->time_to_born, p->number);
	if (number == 4)
		printf("%ld %d is thinking\n", get_time() - p->time_to_born,
			   p->number);
	if (number == 5)
		printf("%ld %d is dead\n", get_time() - p->time_to_born, p->number);;
	if (number == 6)
		printf("%ld %d Stop the emulation. The philosopher ate the right number"
			   "of times!\n", get_time() - p->time_to_born, p->number);
	pthread_mutex_unlock(&p->data->write);
}

void	my_usleep(long int value)
{
	long int	check;
	long int	stop;

	check = get_time();
	stop = value / 1000;
	while ((get_time() - check) < stop)
		usleep(100);
}
