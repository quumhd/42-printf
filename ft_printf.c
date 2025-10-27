/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:21:05 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/27 17:04:38 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*(*g_convert[])(t_tostring, va_list) = {
['c'] = &ft_char,
['s'] = &ft_str,
['p'] = &ft_pointer,
['d'] = &ft_num,
['i'] = &ft_num,
['u'] = &ft_num,
['x'] = &ft_put_hex,
['X'] = &ft_put_uphex,
['%'] = ft_percent
};

static t_extended_list(*g_fill[])(t_extended_list)= {
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
	// printf("type[%d] = %d\n", i, type[i]);
	if (g_fill[(int)type[i]])
		extended_list.parse_list = g_fill[type[i]](extended_list).parse_list;
	va_end(extended_list.args);
	return (extended_list.parse_list);
}

int	ft_choose_arg(const char *type, va_list args, size_t *output_counter, int length, int i)
{
	char			*s;
	t_parse_list	parse_list;
	t_tostring		tostring;

	memset(&parse_list, 0, sizeof(t_parse_list));
	parse_list.i = i;
	while (!g_convert[(int)type[parse_list.i]] && parse_list.i < length && type[parse_list.i] != '%')
	{
		parse_list = ft_fill_list(type, parse_list, args, parse_list.i);
		parse_list.i++;
	}
	// printf("width = %d\n", parse_list.width);
	// printf("minus = %d\n", parse_list.minus);
	// printf("zero = %d\n", parse_list.zero);
	// printf("dot =  %d\n", parse_list.dot);
	// printf("precision = %d\n", parse_list.precision);
	// printf("hash = %d\n", parse_list.hash);)
	// printf("space = %d\n", parse_list.space);
	// printf("plus = %d\n", parse_list.plus);
	tostring.parse_list = parse_list;
	s = g_convert[type[parse_list.i]](tostring, args);
	*output_counter = ft_putstr(s);
	free(s);
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
		if(i < length)
		{
			i = ft_choose_arg(type, args, &output_counter, length, i + 1);
			i++;
		}
	}
	va_end(args);
	return (output_counter);
}

int	main(void)
{
	int i = ft_printf("%s hallo %d\n", "test", 255);
	printf("%d\n", i);
	
	// int i = 0;
	// int *ptr = &i;
	// ft_printf("Char:	%c\nString:	%s\nPtr:	%p\nInt:	%d\nu_Int	%u\nx_Hex:	%x\nX_Hex:	%X\n%%", 'a', "Hallo", ptr, -42, 42, -75, -75);
	// printf("%+538d\n", 255);
	// int i = 0;
	// int *ptr = &i;
	// ft_printf("Meine Zahl ist: %d in Hex %x String %s, char %c%%, pointer%p\n", 255, 255, "string", '!', ptr);
	//    printf("Meine Zahl ist: %d in Hex %x String %s, char %c%%, pointer%p\n", 255, 255, "string", '!', ptr);
	// ft_printf("%%bc\n");
	//    printf("%%bc\n");
}
