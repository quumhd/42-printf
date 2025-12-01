/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:22:59 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/01 16:04:29 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *type, ...);
size_t	ft_choose_arg(const char *type, va_list args, size_t *count, size_t i);

int		ft_char(va_list args);
int		ft_str(va_list args);
int		ft_pointer(va_list args);
int		ft_num(va_list args);
int		ft_unum(va_list args);
int		ft_put_hex(va_list args);
int		ft_put_uphex(va_list args);
int		ft_percent(va_list args);

size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_putchar(int c);
size_t	ft_putstr(char *s);
int		ft_put_base(char *base, ssize_t num, int *length);
int		ft_put_pbase(char *base, size_t num, int *length);
int		ft_put_hbase(char *base, unsigned int num, int *length);

#endif
