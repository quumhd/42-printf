/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:21:05 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/30 12:25:13 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parse_list	ft_fill(const char *type, t_parse_list pl, va_list args, int i)
{
	int				counter;
	t_extended_list	extended_list;

	t_extended_list (*fill[128])(t_extended_list);
	counter = 48;
	while (++counter <= 57)
		fill[counter] = &ft_fill_width;
	fill['.'] = &ft_fill_precision;
	fill['-'] = &ft_fill_minus;
	fill['+'] = &ft_fill_plus;
	fill[' '] = &ft_fill_space;
	fill['#'] = &ft_fill_hash;
	fill['0'] = &ft_fill_zero;
	va_copy(extended_list.args, args);
	extended_list.type = type;
	extended_list.parse_list = pl;
	if (fill[(int)type[i]])
		extended_list.parse_list = fill[type[i]](extended_list).parse_list;
	va_end(extended_list.args);
	return (extended_list.parse_list);
}

int	ft_choose_arg(const char *type, va_list args, size_t *o_c, int i)
{
	char			*s;
	int				len;
	t_parse_list	parse_list;
	int				(*convert[128])(va_list);

	convert['c'] = &ft_char;
	convert['s'] = &ft_str;
	convert['p'] = &ft_pointer;
	convert['d'] = &ft_num;
	convert['i'] = &ft_num;
	convert['u'] = &ft_unum;
	convert['x'] = &ft_put_hex;
	convert['X'] = &ft_put_uphex;
	convert['%'] = ft_percent;
	len = ft_strlen(type);
	ft_memset(&parse_list, 0, sizeof(t_parse_list));
	parse_list.i = i;
	while (!convert[(int)type[parse_list.i]] && parse_list.i < len
		&& type[parse_list.i] != '%')
	{
		parse_list = ft_fill(type, parse_list, args, parse_list.i);
		parse_list.i++;
	}
	*o_c = *o_c + convert[type[parse_list.i]](args);
	return (parse_list.i);
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
// 	int m;
// 	int o;
// 	m = ft_printf(" %p %p \n", 0, 0);
// 	o = printf(" %p %p \n", 0, 0);
// 	printf("%d\n%d\n", m, o);
// }
