/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:55:14 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/27 17:04:39 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char(t_tostring tostring, va_list args)
{
	char	c;
	char	*s;
	int		length;

	c = va_arg(args, int);
	s = malloc(1 + 1);
	if(!s)
		return (NULL);
	memset(s, '0', 2);
	s[1] = '\0';
	s[0] = c;
	return (s);
}

char	*ft_str(t_tostring tostring, va_list args)
{
	int		i;
	int		j;
	int		length;;
	char	*s;
	char	*new;

	i = 0;
	s = va_arg(args, char *);
	j = ft_strlen(s);
	length = ft_strlen(s) + 1;
	new = malloc(length + 1 * sizeof(char));
	if(!new)
		return (NULL);
	ft_memset(new, '0', length);
	new[length - 1] = '\0';
	while (s[i])
	{
		new[length - j - 1] = s[i];
		i++;
		j--;
	}
	return (new);
}

char	*ft_pointer(t_tostring tostring, va_list args)
{
	size_t	n;
	int		temp;
	int		length;
	char	*char_num;
	
	n = va_arg(args, size_t);
	length = ft_count_hex(n) + 2 + 1;
	char_num = (char *)malloc(length * sizeof(char));
	if (!char_num)
		return (NULL);
	ft_memset(char_num, '0', length);
	char_num[length - 1] = '\0';
	char_num[length - ft_count_u_hex(n) - 3] = '0';
	char_num[length - ft_count_u_hex(n) - 2] = 'x';
	if (n == 0)
		char_num[length - 1] = '0';
	while (n != 0)
	{
		if (n < 0)
		{
			temp = n % -16;
			temp = temp * -1;
		}
		else
			temp = n % 16;
		if(temp < 10)
			char_num[length - 2] = temp + '0';
		else
			char_num[length - 2] = temp - 10 + 'a';
		n = n / 16;
		length--;
	}
	return (char_num);
}

char	*ft_num(t_tostring tostring, va_list args)
{
	int		n;
	int		length;
	char	*char_num;

	n = va_arg(args, ssize_t);
	length = ft_count_digits(n) + 1;
	char_num = (char *)malloc(length * sizeof(char));
	if (!char_num)
		return (NULL);
	ft_memset(char_num, '0', length);
	char_num[length - 1] = '\0';
	if (n < 0)
		char_num[length - ft_count_digits(n) - 1] = '-';
	if (n == 0)
		char_num[length - 1] = '0';
	while (n != 0)
	{
		if (n > 0)
			char_num[length - 2] = n % 10 + '0';
		else
			char_num[length - 2] = (n % 10 * -1) + '0';
		n = n / 10;
		length--;
	}
	return (char_num);
}

char	*ft_put_hex(t_tostring tostring, va_list args)
{
	int		n;
	int		temp;
	int		length;
	char	*char_num;
	
	n = va_arg(args, int);
	length = ft_count_hex(n) + 1;
	char_num = (char *)malloc(length * sizeof(char));
	if (!char_num)
		return (NULL);
	ft_memset(char_num, '0', length);
	char_num[length - 1] = '\0';
	if (n < 0)
		char_num[length - ft_count_hex(n) - 1] = '-';
	if (n == 0)
		char_num[length - 1] = '0';
	while (n != 0)
	{
		if (n < 0)
			temp = n % -16 * -1;
		else
			temp = n % 16;
		if(temp < 10)
			char_num[length - 2] = temp + '0';
		else
			char_num[length - 2] = temp - 10 + 'a';
		n = n / 16;
		length--;
	}
	return (char_num);
}

char	*ft_put_uphex(t_tostring tostring, va_list args)
{
	int		n;
	int		temp;
	int		length;
	char	*char_num;
	
	n = va_arg(args, int);
	length = ft_count_hex(n) + 1;
	char_num = (char *)malloc(length * sizeof(char));
	if (!char_num)
		return (NULL);
	ft_memset(char_num, '0', length);
	char_num[length - 1] = '\0';
	if (n < 0)
		char_num[length - ft_count_hex(n) - 1] = '-';
	if (n == 0)
		char_num[length - 1] = '0';
	while (n != 0)
	{
		if (n < 0)
			temp = n % -16 * -1;
		else
			temp = n % 16;
		if(temp < 10)
			char_num[length - 2] = temp + '0';
		else
			char_num[length - 2] = temp - 10 + 'A';
		n = n / 16;
		length--;
	}
	return (char_num);
}

char	*ft_percent(t_tostring tostring, va_list args)
{
	char	c;
	char	*s;
	int		length;

	c = '%';
	s = malloc(1 + 1);
	if(!s)
		return (NULL);
	memset(s, '0', length);
	s[1] = '\0';
	s[0] = c;
	return (s);
}

size_t	ft_putchar(int c)
{
	static	size_t output_counter;

	write(1, &c, 1);
	output_counter++;
	return (output_counter);
}

size_t	ft_putstr(char *s)
{
	int	i;
	size_t	output_counter;

	i = -1;
	while (s[++i])
		output_counter = ft_putchar(s[i]);
	return (output_counter);
}
