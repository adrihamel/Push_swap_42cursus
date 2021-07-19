/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:01:05 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/18 20:24:54 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 4096

# define INT_MIN -2147483647

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct s_file
{
	int				fd;
	char			buf[BUFF_SIZE + 1];
	int				i;
}					t_file;

size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
char				*ft_strnew(size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strdup(char const *s1);
char				*ft_itoa(int n);
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstcpy(t_list *lst);
void				ft_lstappend(t_list **lst, t_list *link);
int					ft_putwchar(wchar_t c);
void				ft_array_swap(int *array, int i1, int i2);
t_file				*ft_fopen(const char *path);
int					ft_fclose(t_file **stream);

#endif
