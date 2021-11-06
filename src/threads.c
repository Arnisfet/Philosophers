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
		p->data[i].number = i;
		pthread_create(&p->data[i].arr_ph, NULL, ft_actions,	&(p->data[i])); // Сделай проверку на выделение потоков
		printf("%lu\n", p->data[i].arr_ph);
		i++;
	}
	i = 0;
	while (i < p->philo)
	{
		pthread_join(p->data[i].arr_ph, NULL);
		i++;
	}
}