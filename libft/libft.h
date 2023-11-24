/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:35:34 by tbornema          #+#    #+#             */
/*   Updated: 2023/10/12 12:45:42 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memset(void *s, int c, size_t len);
void		*ft_memcpy(void *dest, const void *src, size_t len);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			*ft_strnintcpy(int *dest, int *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
void		ft_strintrev(int *str, int *len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int character);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			*ft_safestr(int	*str, int len);
int			*ft_safeinitstr(int len);
int			**ft_safearray(int **argv, int size);
int			**ft_safeinitarray(int size);
void		ft_freearray(int **array, int count);
int			ft_countarray(char **array);
size_t		ft_numlen(int num);
char		*ft_strncpy(char *dest, const char *src, size_t n);
int			ft_handle_char(va_list args);
int			ft_handle_string(va_list args);
int			ft_handle_pointer(void *ptr);
int			ft_handle_decimal(int arg);
int			ft_handle_unsigned_decimal(va_list args);
int			ft_handle_hexadecimal(unsigned int num, int uppercase);
int			ft_handle_percent(void);
int			ft_handle_unknown();
int			ft_handle_placeholder(const char *format, va_list args);
int			ft_uint_len(unsigned int num);
int			ft_is_specifier_type(char c);
int			ft_specifier_length(const char *format);
int			ft_specifier_skip(const char *fmt);
int			ft_printf(const char *format, ...);
void		ft_int_to_ascii(long long num, char *str);
void		ft_uint_to_ascii(unsigned long long num, char *buffer);
char		*ft_ulltoa(unsigned long long n);
void		ft_strrev(char *str);
char		ft_get_specifier(const char *fmt);
void		ft_write_integral_part(int integral, int *num_digits);
void		ft_write_fractional_part(double num, int precision);
int			ft_ptrlen(uintptr_t num);
int			ft_initialize_buffer(const size_t buffer_len);
void		ft_write_buffer(const size_t buffer_len);
void		ft_handle_null_pointer(void);
size_t		ft_handle_non_null_pointer(void *ptr);
const char	*ft_case(int alphacase);
void		ft_printhex(unsigned int num, const char *hexdig, int numdig);
void		ft_freechararray(char  **array);
char 		**ft_safeinitchararray(char  size);
char 		**ft_safechararray(char  **argv);
char 		*ft_safeinitcharstr(char 	*str);
char		*ft_safecharstr(char	*str);
int			ft_absolute(int num);
int			ft_getmaxint(int *array, int *count);
int			ft_getlowint(int *array, int *count);
char		*ft_straddc(char *str, char c);
int			ft_strisalnum(char	*str);
char 		*ft_safeinitcharstrplus(char *str, int n);
#endif