/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:39:59 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/01 16:04:18 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	void *test;
// 	test = (void *)malloc(5);
// 	printf("%s\n%s", (char *)ft_memset(test, 111, 5), 
// (char *)memset(test, 111, 5));
// }