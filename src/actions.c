#include "../philo.h"

void	put_fork(t_attribute *p)
{
	if ((p->number - p->data->philo) == 0)
	{
		pthread_mutex_lock(&p->data->forks[0]);
		display_message(p, 1);
		pthread_mutex_lock(&p->data->forks[p->number]);
		display_message(p, 1);
	}
	if (p->number == 0)
	{
		pthread_mutex_lock(&p->data->forks[p->number]);
		display_message(p, 1);
		pthread_mutex_lock(&p->data->forks[0]);
		display_message(p, 1);
	}
	else
	{
		pthread_mutex_lock(&p->data->forks[p->number]);
		display_message(p, 1);
		pthread_mutex_lock(&p->data->forks[p->number + 1]);
		display_message(p, 1);
	}
}