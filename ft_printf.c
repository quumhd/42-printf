/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:21:05 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/25 13:01:39 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*(*g_convert[])(va_list args,  char *s) = {
// ['c'] = &ft_putchar
// };

static void	(*g_convert[])(char c) = {
['c'] = &ft_putchar
};

static t_extended_list(*g_fill[256])(t_extended_list)= {
['1' ... '9'] = &ft_fill_width,
['.'] = &ft_fill_precision,
['-'] = &ft_fill_minus,
['+'] = &ft_fill_plus,
[' '] = &ft_fill_space,
['#'] = &ft_fill_hash,
['0'] = &ft_fill_zero
};

t_parse_list	ft_fill_list(const char *type, t_parse_list parse_list, va_list args, int i)
{
	t_extended_list extended_list;

	va_copy(extended_list.args, args);
	extended_list.type = type;
	extended_list.parse_list = parse_list;
	printf("type[%d] = %d\n", i, type[i]);
	if (g_fill[(int)type[i]])
		parse_list = g_fill[type[i]](extended_list).parse_list;
		va_end(extended_list.args);
		return (extended_list.parse_list);
}

int	ft_choose_arg(const char *type, va_list args, int length, int i)
{
	// char			*s;
	t_parse_list	parse_list;

	memset(&parse_list, 0, sizeof(t_parse_list));
	parse_list.i = i;
	while (!g_convert[(int)type[parse_list.i]] && parse_list.i < length)
	{
		ft_fill_list(type, parse_list, args, parse_list.i);
		parse_list.i++;
	}
	printf("width = %d\n", parse_list.width);
	g_convert[(int)type[parse_list.i]](va_arg(args, int));
	return (parse_list.i);
}

int	ft_printf(const char *type, ...)
{
	size_t	i;
	size_t	length;
	va_list	params;

	i = 0;
	length = ft_strlen(type);
	va_start(params, type);
	while (i < length)
	{
		while (type[i] != '%' && i < length)
		{
			ft_putchar(type[i]);
			i++;
		}
		if(i < length)
		{
			i = ft_choose_arg(type, params, length, i + 1);
			i++;
		}
	}
	va_end(params);
	return (1);
}

int	main(void)
{
	ft_printf("%0c wasd test\n%-10c\n", 'a', 'b');
	// printf("%+538d\n", 255);
	// int i = 0;
	// int *ptr = &i;
	// ft_printf("Meine Zahl ist: %d in Hex %x String %s, char %c%%, pointer%p\n", 255, 255, "string", '!', ptr);
	//    printf("Meine Zahl ist: %d in Hex %x String %s, char %c%%, pointer%p\n", 255, 255, "string", '!', ptr);
	// ft_printf("%%bc\n");
	//    printf("%%bc\n");
}
