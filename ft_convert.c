/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:55:14 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/29 17:23:24 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(va_list args)
{
	int				length;
	unsigned long	num;

	length = 0;
	num = va_arg(args, unsigned long);
	if (!num)
		return (ft_putstr("(nil)"));
	ft_putchar('0');
	ft_putchar('x');
	ft_put_pbase("0123456789abcdef", num, &length);
	return (length + 2);
}

int	ft_num(va_list args)
{
	ssize_t	num;
	int		length;

	length = 0;
	num = va_arg(args, int);
	if (num < 0)
	{
		ft_putchar('-');
		length++;
		num = num * -1;
	}
	ft_put_base("0123456789", num, &length);
	return (length);
}

int	ft_unum(va_list args)
{
	ssize_t	num;
	int		length;

	length = 0;
	num = va_arg(args, unsigned int);
	if (num < 0)
	{
		ft_putchar('-');
		length++;
		num = num * -1;
	}
	ft_put_hbase("0123456789", num, &length);
	return (length);
}

int	ft_put_hex(va_list args)
{
	int		num;
	int		length;

	length = 0;
	num = va_arg(args, int);
	ft_put_hbase("0123456789abcdef", num, &length);
	return (length);
}

int	ft_put_uphex(va_list args)
{
	int		num;
	int		length;

	length = 0;
	num = va_arg(args, int);
	ft_put_hbase("0123456789ABCDEF", num, &length);
	return (length);
}
