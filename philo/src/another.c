/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:35:41 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/28 13:06:53 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	ft_atoi(const char *str)
{
	char			*p;
	long int		x;
	long int		minus;

	x = 0;
	minus = 1;
	p = (char *)str;
	while (*p == '\t' || *p == '\n' || *p == '\v' || *p == '\f' || *p == '\r'
		|| *p == ' ')
		p++;
	if (*p == 45 || *p == 43)
	{
		if (*p == 45)
			minus *= -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		x = x * 10 + (*p - '0');
		p++;
	}
	return (x * minus);
}

void	error_message(void)
{
	printf("Bad arg\n");
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

int	display_message(t_attribute *p, int number)
{
	pthread_mutex_lock(&p->data->write);
	if (number == 1)
		printf("%ld %d has taken a fork\n", get_time() - p->time_to_born_ph,
			p->number);
	if (number == 2)
		printf("%ld %d is eating\n", get_time() - p->time_to_born_ph, p->number);
	if (number == 3 && p->data->death_flag != 1)
		printf("%ld %d is sleeping\n", get_time() - p->time_to_born_ph,
			p->number);
	if (number == 4)
		printf("%ld %d is thinking\n", get_time() - p->time_to_born_ph,
			p->number);
	if (number == 5)
		printf("%ld %d is dead\n", get_time() - p->time_to_born_ph, p->number);
	if (number == 6)
		printf("%ld %d The philosopher ate the right number"
			"of times!\n", get_time() - p->time_to_born_ph, p->number);
	pthread_mutex_unlock(&p->data->write);
	return (0);
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
