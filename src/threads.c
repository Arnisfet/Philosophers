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
	}
}

