/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_list2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:24:39 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/29 17:25:29 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_extended_list	ft_fill_precision(t_extended_list e_l)
{
	if (e_l.parse_list.precision == 0 && e_l.parse_list.dot == 0)
	{
		e_l.parse_list.dot = 1;
		e_l.parse_list.i++;
		e_l.parse_list.precision = ft_atoi(&e_l.type[e_l.parse_list.i]);
		while (e_l.type[e_l.parse_list.i] >= '0'
			&& e_l.type[e_l.parse_list.i] <= '9')
			e_l.parse_list.i++;
		e_l.parse_list.i = e_l.parse_list.i - 1;
	}
	else
		e_l.parse_list.dot = -1;
	return (e_l);
}

t_extended_list	ft_fill_width(t_extended_list e_l)
{
	if (e_l.parse_list.width == 0
		&& e_l.parse_list.dot == 0)
	{
		e_l.parse_list.width = ft_atoi(&e_l.type[e_l.parse_list.i]);
		while (e_l.type[e_l.parse_list.i] >= '0'
			&& e_l.type[e_l.parse_list.i] <= '9')
			e_l.parse_list.i++;
		e_l.parse_list.i = e_l.parse_list.i - 1;
	}
	else if (e_l.parse_list.width != 0
		&& e_l.parse_list.dot != 0)
		e_l.parse_list.width = -1;
	return (e_l);
}
