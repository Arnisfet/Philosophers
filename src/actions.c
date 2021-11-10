#include "../philo.h"

void	think(t_attribute *p)
{

}

void	eat(t_attribute *p)
{
	pthread_mutex_lock(&p->data->eat);
	display_message(p, 2);
	usleep(p->data->time_to_eat * 1000);
	pthread_mutex_unlock(&p->data->eat);
}

void	put_fork(t_attribute *p)
{
	if (p->number == 5)
	{
		pthread_mutex_lock(&p->data->forks[p->right_fork]);
		display_message(p, 1);
		pthread_mutex_lock(&p->data->forks[p->left_fork]);
		display_message(p, 1);
	}
	else
	{
		pthread_mutex_lock(&p->data->forks[p->left_fork]);
		display_message(p, 1);
		pthread_mutex_lock(&p->data->forks[p->right_fork]);
		display_message(p, 1);
	}
}

void	fall_asleep(t_attribute *p)
{
	display_message(p, 3);
	pthread_mutex_unlock(&p->data->forks[p->left_fork]);
	pthread_mutex_unlock(&p->data->forks[p->right_fork]);
	usleep(p->data->time_to_sleep * 1000);
}