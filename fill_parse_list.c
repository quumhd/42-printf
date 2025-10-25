/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:27:14 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/25 16:25:31 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_extended_list	ft_fill_width(t_extended_list extended_list)
{
	if (extended_list.parse_list.width == 0
		&& extended_list.parse_list.dot == 0)
	{
		extended_list.parse_list.width = ft_atoi(&extended_list.type[extended_list.parse_list.i]);
		while (extended_list.type[extended_list.parse_list.i] >= '0'
			&& extended_list.type[extended_list.parse_list.i] <= '9')
			extended_list.parse_list.i++;
		extended_list.parse_list.i = extended_list.parse_list.i - 1;
	}
	else if (extended_list.parse_list.width != 0
		&& extended_list.parse_list.dot != 0)
		extended_list.parse_list.width = -1;
	return (extended_list);
}

t_extended_list	ft_fill_minus(t_extended_list extended_list)
{
	if (extended_list.parse_list.minus == 0)
		extended_list.parse_list.minus = 1;
	else
		extended_list.parse_list.minus = -1;
	return (extended_list);
}

t_extended_list	ft_fill_zero(t_extended_list extended_list)
{
	if (extended_list.parse_list.zero == 0)
		extended_list.parse_list.zero = 1;
	else
		extended_list.parse_list.zero = -1;
	return (extended_list);
}

t_extended_list	ft_fill_precision(t_extended_list extended_list)
{
	if (extended_list.parse_list.precision == 0 && extended_list.parse_list.dot == 0)
	{
		extended_list.parse_list.dot = 1;
		extended_list.parse_list.i++;
		extended_list.parse_list.precision = ft_atoi(&extended_list.type[extended_list.parse_list.i]);
		while (extended_list.type[extended_list.parse_list.i] >= '0'
			&& extended_list.type[extended_list.parse_list.i] <= '9')
		extended_list.parse_list.i++;
		extended_list.parse_list.i = extended_list.parse_list.i - 1;
	}
	else
		extended_list.parse_list.dot = -1;
	return (extended_list);
}

t_extended_list	ft_fill_hash(t_extended_list extended_list)
{
	if (extended_list.parse_list.hash == 0)
		extended_list.parse_list.hash = 1;
	else
		extended_list.parse_list.hash = -1;
	return (extended_list);
}

t_extended_list	ft_fill_space(t_extended_list extended_list)
{
	if (extended_list.parse_list.space == 0)
		extended_list.parse_list.space = 1;
	else
		extended_list.parse_list.space = -1;
	return (extended_list);
}

t_extended_list	ft_fill_plus(t_extended_list extended_list)
{
	if (extended_list.parse_list.plus == 0)
		extended_list.parse_list.plus = 1;
	else
		extended_list.parse_list.plus = -1;
	return (extended_list);
}
