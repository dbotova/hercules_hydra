/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 19:16:14 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/23 19:30:55 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <stdint.h>
# include <float.h>
# define BUFF_SIZE 2
# define ABS(x) (x < 0) ? (-x) : (x)
# define MIN(x, y) (x < y) ? (x) : (y)
# define MAX(x, y) (x > y) ? (x) : (y)
# define ROUND(x) (unsigned long long)(x + 5)
# define SPECS "sSpdDioOuUxXcCfF%"
# define STR "sSpdDioOuUxXcC +-.0123456789zlhj#%*L'"
# define FLAGS "+-.0123456789zlhj#* L'"
# define SMART_FREE(x) {free(x); x = NULL;}

typedef struct			s_file
{
	int					fd;
	char				*buf;
	struct s_file		*next;
}						t_file;

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

union					u_types
{
	char				*s;
	char				c;
	int					d;
	int					is_digit;
	intmax_t			ix;
	unsigned int		u;
	unsigned long		ul;
	long long			ll;
	long				l;
	unsigned long long	ull;
	long long			p;
	char				ar[2];
	unsigned char		uc;
	unsigned short		us;
	wchar_t				*ws;
	wchar_t				wc;
	double				f;
	long double			lf;
};

typedef struct			s_flags
{
	int					is_hash;
	int					width;
	int					is_dot;
	int					is_minus;
	int					is_plus;
	int					is_zero;
	int					cutoff;
	int					is_l;
	int					is_j;
	int					is_space;
	int					is_h;
	int					is_o;
	int					is_z;
	int					is_cl;
	int					is_separete;
	char				*target;
}						t_flags;

int						ft_printf(char *args, ...);
char					*ft_ltoa_base(long long n, int base);
int						get_next_line(const int fd, char **line);
int						ft_strncmp(char *s1, char *s2, size_t n);
int						ft_atoi(char *str);
size_t					ft_strlen(const char *str);
char					*ft_strchr(const char *str, int c);
char					*ft_strrchr(const char *str, int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_strcmp(const char *str1, const char *str2);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_ispunct(int c);
char					*ft_strdup(const char *string);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
size_t					ft_strlcat(char *destination, const char *source,
								size_t size);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
void					*ft_memset (void *ptr, int value, size_t num);
void					ft_bzero(void *pointer, int length);
void					*ft_memcpy(void *str1, const void *str2, size_t n);
void					*ft_memccpy(void *str1, const void *str2, int c,
						size_t n);
void					*ft_memmove(void *str1, const void *str2, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char(*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
void					ft_putchar(int c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_itoa_base(int n, int base);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strupcase(char *str);
char					*ft_strulowcase(char *str);
t_list					*ft_list_last(t_list *begin_list);
int						ft_getnum(char *str, int *value);
void					ft_putwchar(wchar_t chr);
void					ft_putwstr(wchar_t *str, size_t size);
size_t					ft_wstrlen(wchar_t *str);
size_t					ft_wcharlen(wchar_t c);
char					*ft_num_separete(char *str);
unsigned int			ft_power(int n, int pow);
void					ft_putlnbr(unsigned int nb);
void					ft_putnstr(char const *s, int n);
char					*ft_ftoa_precision(long double n, int precision);
char					*ft_ultoa_base(unsigned long long nb, int base);
int						ft_nbrsize(long n);
t_flags					*ft_newflagslst();
char					*ft_getflags(char *ptr, t_flags **flags, va_list ap);
void					ft_create_jump_table(int(*jump_table[])(va_list,
						union u_types, t_flags*));
int						ft_float_print(va_list ap, union u_types tp,
						t_flags *flags);
char					*ft_num_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_char_read(char *target, t_flags *flags,
						char **prefix, char **width);
wchar_t					*ft_wchar_read(wchar_t *target, t_flags *flags,
						char **prefix, char **width);
wchar_t					*ft_wstr_read(wchar_t *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_str_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_undef_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_hex_read(t_flags *flags,
						char **prefix, char **width, char *hash);
char					*ft_float_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_pointer_read(char *target, t_flags *flags,
						char **prefix, char **width);
int						ft_octa_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cocta_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_int_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cint_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_hex_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_chex_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_unsigned_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cunsigned_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_str_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cstr_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_pointer_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_char_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cchar_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_print(union u_types tp, t_flags *flags);
int						ft_undef_print(char *ptr, t_flags *flags);
#endif
