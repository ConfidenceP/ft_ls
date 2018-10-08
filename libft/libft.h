/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:50:21 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/24 17:10:51 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					arraylen(char **array);
void				free2d(char **array);
char				**arraypush(char **array, char *str);
void				*ft_memset(void *dest, int src, size_t num_bits);
int					ft_atoi(const char *str);
void				ft_bzero(void *str, int num_bit);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t num_bits);
void				*ft_memmove(void *dest, const void *src, size_t num_bits);
void				*ft_memccpy(void *dest, const void *src, int c,
					size_t num_bits);
void				*ft_memchr(const void *str, int c, size_t num_bits);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nbr1);
void				ft_arraydel(char ***arr);
void				ft_putnbr_fd(int nbr1, int fd);
int					ft_memcmp(const void *str1, const void *str2,
					size_t num_bits);
size_t				ft_strlen(const char *str);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *str);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t destsize);
char				*ft_strncat(char *dest, const char *src, size_t num_bits);
int					ft_strncmp(const char *str1, const char *str2,
					size_t num_bits);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t num_bits);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				**ft_array_join(char ***arr, char *str);
char				*ft_strtrim(char const *s);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
int					ft_toupper(int c);
int					ft_tolower(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
