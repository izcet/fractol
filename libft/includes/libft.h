/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:02:27 by irhett            #+#    #+#             */
/*   Updated: 2017/03/22 20:15:28 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_int_matrix
{
	unsigned int	rows;
	unsigned int	cols;
	int				**data;
}					t_int_matrix;

typedef struct		s_double_matrix
{
	unsigned int	rows;
	unsigned int	cols;
	double			**data;
}					t_dub_matrix;

int					ft_atoi(char *str);
char				*ft_itoa(int n);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);

int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_strtolower(char *str);
void				ft_strtoupper(char *str);

void				ft_lstadd(t_list **alst, t_list *elem);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_bzero(void *s, size_t n);
char				*ft_memalloc(size_t size);
void				*ft_memccpy(void *d, const void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *p, int num, size_t len);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char const *s, int fd);

char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dst, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

int					get_next_line(const int fd, char **line);
char				*gnl_concat(char *s1, char *s2, int free1, int free2);

void				ft_swap(void *a, void *b, size_t size);
void				ft_bubblesort_intarr(int *arr, unsigned int len);
int					ft_findbiggest(int *arr, unsigned int arr_len);
unsigned int		ft_numwords(char *str, char del);
unsigned int		ft_wordlen(char *s, char del);
char				*ft_strcapwords(char *str);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

int					ft_error(char *str);

int					ft_usage(char *name, char *args);

t_int_matrix		*init_int_matrix(void);
t_int_matrix		*make_int_matrix(unsigned int len, unsigned int wid);
void				del_int_matrix(t_int_matrix *t);

t_dub_matrix		*init_dub_matrix(void);
t_dub_matrix		*make_dub_matrix(unsigned int len, unsigned int wid);
void				del_dub_matrix(t_dub_matrix *t);

void				mult_int_matrix_scalar(t_int_matrix *t, double factor);
void				plus_int_matrix_scalar(t_int_matrix *t, int factor);

void				mult_dub_matrix_scalar(t_dub_matrix *t, double factor);
void				plus_dub_matrix_scalar(t_dub_matrix *t, double factor);

int					int_dot_product(int *a, int *b, unsigned int len);
double				dub_dot_product(double *a, double *b, unsigned int len);

t_int_matrix		*mult_int_matrix(t_int_matrix *a, t_int_matrix *b);
t_dub_matrix		*mult_dub_matrix(t_dub_matrix *a, t_dub_matrix *b);

int					*int_col(int **a, unsigned int col, unsigned int len);
double				*dub_col(double **a, unsigned int col, unsigned int len);

#endif
