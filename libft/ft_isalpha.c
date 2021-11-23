/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:17:31 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/23 22:40:53 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by Mickey Rudge on 5/1/21.
//
// Возвращает кодовый номер символа, если приходит символ, если нет, то
// возвращает 0.

#include "libft.h"

int	ft_isalpha(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return (ch);
	return (0);
}
