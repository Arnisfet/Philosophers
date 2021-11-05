#include "../philo.h"



void *ft_check(void *check)
{

}

void	threads(t_data *p)
{
	int i;

	i = 0;
	p->start = get_time();
	while (i < p->philo)
	{
		p->data[i].number = i;
		pthread_create(&p->data[i].arr_ph, NULL, ft_check,	&(p->data[i]
		.arr_ph)); // Сделай проверку на выделение потоков
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