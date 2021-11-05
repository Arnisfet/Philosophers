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