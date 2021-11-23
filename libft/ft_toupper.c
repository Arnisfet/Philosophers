/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:19:35 by mrudge            #+#    #+#             */
/*   Updated: 2021/11/23 22:40:53 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by Mickey Rudge on 5/1/21.
//

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		ch -= 'a' - 'A';
	return (ch);
}
