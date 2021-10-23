/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:40:15 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/19 20:39:38 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Этапы написания программы:
 * 1) Создание прасера для 5 параметров: колв-во философов(и вилок), время до
 * смерти (время в мс/с, через которое философ умирает, если не начал есть)
 * время для еды (время в которое филосов начинает есть), время на сон (время
 * через которое филосов начинает спать) , количество раз, которое философ
 * должен поесть.
 *
 * Варианты ошибок: 1) Кол-во аргументов меньше 5 или больше 6; */

#include "philo.h"

void	error_message()
{
	printf("Bad arg");
	exit (0);
}

void	add_to_struct(int ac, long int num, t_data *p)
{
	if (ac == 3)
		p->time_to_sleep = num;
	if (ac == 2)
		p->time_to_eat = num;
	if (ac == 1)
		p->time_to_die = num;
}

void	error_parse(char **av, int ac, t_data *p)
{
	long int number;
	int arg;

	arg = 4;
	if (ac < 5 || ac > 6)
		error_message();
	while (arg != 0)
	{
		number = ft_atoi(av[arg]);
		add_to_struct(arg, number, p);
		if (arg == 1 && number > 200 || number < 1)
			error_message();
		if (arg != 1 && number < 60 || number > 2147483647)
			error_message();
		arg--;
	}
}

void	threads(t_data *p)
{

}

void	initialize(t_data *p)
{

}

int main(int ac, char **av)
{
	t_data *p;

	p = (t_data *)malloc(sizeof (t_data));
	memset(p, 0, sizeof (t_data));
	printf("%li", p->time_to_die);
	error_parse(av, ac, p);
	initialize(p);
	threads(p);
	return 0;
}
