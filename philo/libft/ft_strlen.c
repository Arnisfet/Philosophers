/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:19:04 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/23 22:46:21 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by vitya on 23.04.2021.
//

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
