#include "../philo.h"

/*
 * 1) Действия философов в рамках алгоритма:
 * 		а) Взять 2 вилки и поесть
 * 		б) Поспать
 * 		в) Подумать
 * 		г) Все заново, пока не умрут
 * */

void *ft_actions(void *check)
{
	t_attribute 	*p;

	p = (t_attribute *)check;
	p->time_to_born = get_time();
	p->last_eat = get_time();
	p->limit = p->last_eat + p->data->time_to_die;
	p->eating = 0;
	p->count_eat_ph = 0;
	while (1)
	{
		put_fork(p);
		eat(p);
		fall_asleep(p);
		display_message(p, 4);
	}
}

void	join(t_data *p)
{
	int i;

	i = 0;
	while (i < p->philo)
	{
		pthread_join(p->philo_t[i].arr_ph, NULL);
		i++;
	}
	pthread_join(p->monitor, NULL);
}

void	threads(t_data *p, int number)
{
	int i;

	i = 1;
	if (number == 2)
		i = 0;

	while (i < p->philo)
	{
			p->philo_t[i].number = i + 1;
			p->philo_t[i].data = p;
			p->philo_t[i].left_fork = i;
			p->philo_t[i].right_fork = ((i + 1) % p->philo);
			pthread_create(&p->philo_t[i].arr_ph, NULL, ft_actions, &(p->philo_t[i])); // Сделай проверку на выделение потоков
			i += 2;
			usleep(1000);
	}
	if (number == 1)
	{
		pthread_create(&p->monitor, NULL, death_monitor, p);
		pthread_detach(p->monitor);
	}
}

void	*death_monitor(void *check)
{
	int i;
	t_data *p;

	p = (t_data *)check;
	i = 0;
	while (21)
	{
		while (i < p->philo)
		{
			if (p->philo_t[i].count_eat_ph >= p->count_eat && p->count_eat
			!= 0)
				display_message(&p->philo_t[i], 6);
			if ((get_time() > p->philo_t[i].limit) && !p->philo_t[i].eating)
				display_message(&p->philo_t[i], 5);
			i++;
		}
		i = 0;
	}
}