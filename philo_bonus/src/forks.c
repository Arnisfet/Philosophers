/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:42:29 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/24 20:28:54 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	forks(t_data *p, int number)
{
	int i;

	i = 1;
	if (number == 2)
		i = 0;
	while (i < p->forks)
	{
		p->forks_t[i].pid = fork();
		if (p->forks_t[i].pid == -1)
		{
			printf("Fork doesnt made");
			exit(0);
		}
		if (p->forks_t[i].pid == 0)
		{
			printf("Good fooooooork! %d pid, count %d\n", p->forks_t[i].pid, i);
		}
		i++;
		usleep(1000);
	}
	exit_forks(p);
}

void	exit_forks(t_data *p)
{
	int	i;
	int	status;

	i = 0;
	while (i < p->forks)
	{
		waitpid(-1, &status, 0);
		i++;
	}
}