/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:35:41 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/15 11:38:09 by mrudge           ###   ########.fr       */
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

void	display_message(t_attribute *p, int number)
{
	pthread_mutex_lock(&p->data->write);
	ft_putnbr_fd(get_time() - p->time_to_born, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(p->number, 1);
	ft_putchar_fd(' ', 1);
	if (number == 1)
		ft_putstr_fd("has taken a fork", 1);
	if (number == 2)
		ft_putstr_fd("is eating", 1);
	if (number == 3)
		ft_putstr_fd("is sleeping", 1);
	if (number == 4)
		ft_putstr_fd("is thinking", 1);
	if (number == 5)
	{
		ft_putstr_fd("is dead", 1);
		printf(" eat %ld count eat %ld", p->count_eat_ph, p->data->count_eat);
	}
	if (number == 6)
		ft_putstr_fd("Stop the emulation. The philosopher ate the right number "
			"of times!", 1);
	ft_putchar_fd('\n', 1);
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
