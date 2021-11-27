/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:17:41 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/27 18:26:48 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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
		p->forks = num;
//	p->forks = 0;
}

void	error_parse(char **av, int ac, t_data *p)
{
	long int	number;
	int			arg;

	arg = ac - 1;
	if (ac < 5 || ac > 6)
		error_message();
	while (arg != 0)
	{
		number = ft_atoi(av[arg]);
		if ((arg == 1 && number > 200) || number < 1)
			error_message();
		if ((arg != 1 && arg != 5 && number < 60) || number > 2147483647)
			error_message();
		add_to_struct(arg, number, p);
		arg--;
	}
}

void	initialise(t_data *p)
{
//	printf("%d forks, %d tte, %d time to sleep", p->forks, p->time_to_eat,
//		  p->time_to_sleep);
	sem_unlink("write");
	sem_unlink("death");
	sem_unlink("forks");
	p->write = sem_open("write", O_CREAT, 0644, 1);
	p->death = sem_open("death", O_CREAT, 0644, 1);
	p->forks_n = sem_open("forks", O_CREAT, 0644, p->forks_n);
	sem_unlink("write");
	sem_unlink("death");
	sem_unlink("forks");

	// проверка на создание трех семафороф
}

int	main(int ac, char **av)
{
	t_data *p;

	p = (t_data *)malloc(sizeof (t_data));
	p->forks_t = (t_attribute *)malloc(sizeof (t_data) * p->forks);
	error_parse(av, ac, p);
	initialise(p);
	forks(p, 2);
	forks(p, 1);

}