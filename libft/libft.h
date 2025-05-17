/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:02:43 by kationg           #+#    #+#             */
/*   Updated: 2025/05/17 14:54:02 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
#endif
# ifndef MAX_FD
#  define MAX_FD 1024
#endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t n, size_t size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

void			*ft_memchr(const void *str, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memmove(void *dest, const void *src, size_t n);

char			*ft_strdup(const char *s);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnstr(const char *big, const char *little, size_t n);

char			*ft_strrchr(const char *str, int c);

char			*ft_strchr(const char *s, int c);

int				ft_tolower(int c);

int				ft_toupper(int c);

char			*ft_itoa(int n);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strjoin(char const *s1, char const *s2);

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, unsigned int start, size_t len);

void			*ft_memset(void *str, int c, size_t n);

void			*ft_memcpy(void *dest_str, const void *src_str, size_t n);

size_t			ft_strlen(const char *s);

size_t			ft_strlcpy(char *dest, const char *src, size_t size);

size_t			ft_strlcat(char *dest, const char *src, size_t size);

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new_lst);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new_lst);

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

char	*get_next_line(int fd);

#endif
