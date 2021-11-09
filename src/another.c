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
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(p->number, 1);
	ft_putchar_fd('\n', 1);
	pthread_mutex_unlock(&p->data->write);
}