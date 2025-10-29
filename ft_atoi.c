/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:12:47 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/29 12:21:07 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_remove_whitespace(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	return (i);
}

static int	ft_remove_zero(const char *nptr, int i)
{
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] == '0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;

	i = ft_remove_whitespace(nptr);
	if (nptr[i] == '-')
		num = (nptr[ft_remove_zero(nptr, i)] - '0') * -1;
	else if (nptr[i] == '+')
		num = nptr[ft_remove_zero(nptr, i)] - '0';
	else
		num = nptr[ft_remove_zero(nptr, i)] - '0';
	i = ft_remove_zero(nptr, i);
	if (!(nptr[i] >= 48 && nptr[i] <= 57))
		return (0);
	while (nptr[++i] >= 48 && nptr[i] <= 57 && nptr[i])
	{
		if (num > 0)
			num = num * 10 + (nptr[i] - '0');
		else if (num < 0)
			num = num * 10 - (nptr[i] - '0');
	}
	return (num);
}

// int	main(void)
// {
// 	const char *test = "-0000085";
// 	int mein = ft_atoi(test);
// 	int org = atoi(test);
// 	printf("Mein: %d\nOrg:  %d\n", mein, org);
// }
