#include "../philo.h"

void	error_message()
{
	printf("Bad arg");
	exit (0);
}

long int	get_time()
{
	long int	result;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (result);
}


void	display_message(t_attribute *p, int number)
{
	pthread_mutex_lock(&p->data->write);
	ft_putnbr_fd(get_time() - p->time_to_born, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(p->number, 1);
	ft_putchar_fd(' ', 1);
	if (number == 1)
		ft_putstr_fd("has taken a fork", 1);
	if (number == 2)
		ft_putstr_fd("is eating", 1);
	if (number == 3)
		ft_putstr_fd("is sleeping", 1);
	if (number == 4)
		ft_putstr_fd("is thinking", 1);
	if (number == 5)
	{
		ft_putstr_fd("is dead", 1);
		printf(" limit %ld last eat %ld get_time %ld time to born %ld ",
			   p->limit,
			   p->last_eat,
			   get_time(), p->time_to_born);
		exit (0);
	}
	ft_putchar_fd('\n', 1);
	pthread_mutex_unlock(&p->data->write);
}

