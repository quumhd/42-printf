/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:22:59 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/25 15:55:17 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

typedef struct s_parse_list
{
	int	i;
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

t_extended_list	ft_fill_width(t_extended_list parse_list);
t_extended_list	ft_fill_minus(t_extended_list parse_list);
t_extended_list	ft_fill_zero(t_extended_list parse_list);
t_extended_list	ft_fill_precision(t_extended_list parse_list);
t_extended_list	ft_fill_hash(t_extended_list parse_list);
t_extended_list	ft_fill_space(t_extended_list parse_list);
t_extended_list	ft_fill_plus(t_extended_list parse_list);

// char *(*convert[])(char) = 
// {
// 	['c'] = ft_putchar
// 	// ['s'] = 
// 	// ['p'] = 
// 	// ['d'] = 
// 	// ['i'] = 
// 	// ['u'] = 
// 	// ['x'] = 
// 	// ['X'] = 
// 	// ['%'] =  
// };

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_put_hex(ssize_t i, int big);
void	ft_put_pointer(size_t t);
void	ft_put_unsigned(size_t i);

#endif
