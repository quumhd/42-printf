/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:22:57 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/29 17:23:50 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	ft_str(va_list args)
{
	int		i;
	char	*s;

	i = 0;
	s = va_arg(args, char *);
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_percent(va_list args)
{
	return (ft_putchar('%'));
}
