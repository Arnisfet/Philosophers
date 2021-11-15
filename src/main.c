/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:40:15 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/15 15:50:17 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Этапы написания программы:
 * 1) Создание прасера для 5 параметров: колв-во философов(и вилок), время до
 * смерти (время в мс/с, через которое философ умирает, если не начал есть)
 * время до еды (время в которое филосов начинает есть), время на сон (время
 * через которое филосов начинает спать) , количество раз, которое философ
 * должен поесть.
 *
 * Варианты ошибок: 1) Кол-во аргументов меньше 5 или больше 6; */

#include "../philo.h"

void	add_to_struct(int arg, long int num, t_data *p)
{
	if (arg == 5)
	{
		if (num < 0 || num > 2147483647)
			error_message();
		p->count_eat = num;
	}
	if (arg == 4)
		p->time_to_sleep = num;
	if (arg == 3)
		p->time_to_eat = num;
	if (arg == 2)
		p->time_to_die = num;
	if (arg == 1)
		p->philo = num;
	p->philo_t = NULL;
}

void	error_parse(char **av, int ac, t_data *p)
{
	long int	number;
	int			arg;

	p->count_eat = 0;
	p->death_flag = 0;
	arg = ac - 1;
	if (ac < 5 || ac > 6)
		error_message();
	while (arg != 0)
	{
		number = ft_atoi(av[arg]);
		if (arg == 1 && number > 200 || number < 1)
			error_message();
		if (arg != 1 && arg != 5 && number < 60 || number > 2147483647)
			error_message();
		add_to_struct(arg, number, p);
		arg--;
	}
}

int	initialize(t_data *p)
{
	int	i;

	i = 0;
	p->philo_t = (t_attribute *)malloc(sizeof (t_attribute) * p->philo);
	if (!p->philo_t)
		return (0);
	p->forks = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t) * p->philo);
	if (!p->philo_t)
		return (0);
	while (i < p->philo)
		pthread_mutex_init(&p->forks[i++], NULL);
	pthread_mutex_init(&p->write, NULL);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*p;

	p = (t_data *)malloc(sizeof (t_data));
	error_parse(av, ac, p);
	initialize(p);
	if (threads(p, 2))
		return (1);
	if (threads(p, 1))
		return (1);
	join_and_destroy(p);
	return (0);
}
