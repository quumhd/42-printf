/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:27:14 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/29 17:25:41 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
