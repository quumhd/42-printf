/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:22:59 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/29 16:56:28 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_atoi(const char *nptr);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(const char *s);

typedef struct s_parse_list
{
	int	i;
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}	t_parse_list;

typedef struct s_extented_list
{
	va_list			args;
	const char		*type;
	t_parse_list	parse_list;
}	t_extended_list;

typedef struct s_tostring
{
	t_parse_list	parse_list;
}	t_tostring;

int				ft_printf(const char *type, ...);

t_extended_list	ft_fill_width(t_extended_list extended_list);
t_extended_list	ft_fill_minus(t_extended_list extended_list);
t_extended_list	ft_fill_zero(t_extended_list extended_list);
t_extended_list	ft_fill_precision(t_extended_list extended_list);
t_extended_list	ft_fill_hash(t_extended_list extended_list);
t_extended_list	ft_fill_space(t_extended_list extended_list);
t_extended_list	ft_fill_plus(t_extended_list extended_list);

int				ft_char(va_list args);
int				ft_str(va_list args);
int				ft_pointer(va_list args);
int				ft_num(va_list args);
int				ft_unum(va_list args);
int				ft_put_hex(va_list args);
int				ft_put_uphex(va_list args);
int				ft_percent(va_list args);

size_t			ft_putchar(int c);
size_t			ft_putstr(char *s);
void			ft_put_base(char *base, ssize_t num, int *length);
void			ft_put_pbase(char *base, size_t num, int *length);
void			ft_put_hbase(char *base, unsigned int num, int *length);

#endif
