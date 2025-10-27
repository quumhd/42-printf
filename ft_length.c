/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:19:04 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/27 15:37:53 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(int num)
{
	int	i;

	i = 0;
	if (num < 0)
		i++;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

ssize_t	ft_count_hex(ssize_t	num)
{
	int	i;

	i = 0;
	if (num < 0)
		i++;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

size_t	ft_count_u_hex(size_t	num)
{
	int	i;

	i = 0;
	if (num < 0)
		i++;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}