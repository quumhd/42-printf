/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:52:32 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/01 15:44:51 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(int c)
{
	int	check;

	check = write(1, &c, 1);
	return (check);
}

size_t	ft_putstr(char *s)
{
	int		i;
	size_t	output_counter;

	i = -1;
	output_counter = 0;
	while (s[++i])
		output_counter = output_counter + ft_putchar(s[i]);
	return (output_counter);
}

int	ft_put_base(char *base, ssize_t num, int *length)
{
	int		check;
	ssize_t	base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_put_base (base, num / base_len, length);
	check = ft_putchar (base[num % base_len]);
	if (check == -1)
		return (check);
	*length = *length + check;
	return (1);
}

int	ft_put_pbase(char *base, size_t num, int *length)
{
	int		check;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_put_pbase(base, num / base_len, length);
	check = ft_putchar (base[num % base_len]);
	if (check == -1)
		return (check);
	*length = *length + check;
	return (1);
}

int	ft_put_hbase(char *base, unsigned int num, int *length)
{
	int		check;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_put_hbase(base, num / base_len, length);
	check = ft_putchar (base[num % base_len]);
	if (check == -1)
		return (check);
	*length = *length + check;
	return (1);
}
