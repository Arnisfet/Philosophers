#include "../philo.h"



void	eat(t_attribute *p)
{
	display_message(p, 2);
	p->eating = 1;
	p->last_eat = get_time();
	p->limit = p->last_eat + p->data->time_to_die;
	my_usleep(p->data->time_to_eat * 1000);
	p->eating = 0;
	++p->count_eat_ph;
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
	my_usleep(p->data->time_to_sleep * 1000);
}