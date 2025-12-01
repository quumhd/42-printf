/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:21:05 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/01 16:12:37 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_choose_arg(const char *type, va_list args, size_t *count, size_t i)
{
	int				len;
	int				check;
	int				(*convert[128])(va_list);

	ft_memset(convert, 0, sizeof(convert));
	convert['c'] = ft_char;
	convert['s'] = ft_str;
	convert['p'] = ft_pointer;
	convert['d'] = ft_num;
	convert['i'] = ft_num;
	convert['u'] = ft_unum;
	convert['x'] = ft_put_hex;
	convert['X'] = ft_put_uphex;
	convert['%'] = ft_percent;
	len = ft_strlen(type);
	if (convert[(const unsigned char)type[i]])
		check = convert[(const unsigned char)type[i]](args);
	else
		check = ft_percent(args);
	*count = *count + check;
	return (i);
}

int	ft_printf(const char *type, ...)
{
	size_t	i;
	size_t	length;
	size_t	output_counter;
	va_list	args;

	i = 0;
	output_counter = 0;
	length = ft_strlen(type);
	va_start(args, type);
	while (i < length)
	{
		while (type[i] != '%' && i < length)
		{
			ft_putchar(type[i]);
			output_counter++;
			i++;
		}
		if (i < length)
		{
			i = ft_choose_arg(type, args, &output_counter, i + 1);
			i++;
		}
	}
	va_end(args);
	return (output_counter);
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	int m;
// 	m = ft_printf("%h");
// 	ft_printf("%d", m);
// }
