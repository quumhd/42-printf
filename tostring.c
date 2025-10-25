/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:55:14 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/24 15:51:17 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

void	ft_put_hex(ssize_t i, int big)
{
	int		where;
	char	*set;

	where = 0;
	if (big == 0)
		set = "0123456789abcdef";
	else
		set = "0123456789ABCDEF";
	where = i % 16;
	i = i / 16;
	if (where < 0)
	{
		where = where * -1;
		ft_putchar('-');
		i = i * -1;
	}
	if (i != 0)
		ft_put_hex(i, big);
	ft_putchar(set[where]);
}

void	ft_put_pointer(size_t t)
{
	int		where;
	char	*set;

	where = 0;
	set = "0123456789abcdef";
	if (t < 16)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	where = t % 16;
	t = t / 16;
	if (t != 0)
		ft_put_pointer(t);
	ft_putchar(set[where]);
}

void	ft_put_unsigned(size_t i)
{
	char	*set;
	int		where;

	where = 0;
	set = "0123456789";
	where = i % 10;
	i = i / 10;
	if (i != 0)
		ft_put_unsigned(i);
	ft_putchar(set[where]);
}
