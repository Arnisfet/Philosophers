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

	}

}

void	threads(t_data *p)
{
	int i;

	i = 0;
	while (i < p->philo)
	{
		p->philo_t[i].number = i;
		p->philo_t[i].data = p;
		pthread_create(&p->philo_t[i].arr_ph, NULL, ft_actions, &(p->philo_t[i])); // Сделай проверку на выделение потоков
		printf("%lu\n", p->philo_t[i].arr_ph);
		i++;
	}
	i = 0;
	while (i < p->philo)
	{
		pthread_join(p->philo_t[i].arr_ph, NULL);
		i++;
	}
}