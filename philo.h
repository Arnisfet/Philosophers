/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:36:02 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/19 19:36:04 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MY_PHILO_PHILO_H
# define MY_PHILO_PHILO_H

#include <string.h>
#include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_philo_attribute
{
	pthread_t	*arr_ph;
	int	number;
}				t_attribute;

typedef struct s_struct
{
	long int	philo;
	long int	time_to_eat;
	long int	time_to_die;
	long int	time_to_sleep;

	t_attribute *data;
}				t_data;

void	error_message();
void	*ft_check(void *check, t_data *p);

#endif //MY_PHILO_PHILO_H
