/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:03:12 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/01 21:34:48 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_args
{
	int	minus;
	int	plus;
	int	zero;
	int	dot;
	int	hashtag;
	int	space;
	int	width;
	int	star;
}	t_args;

int		ft_printf(const char *format, ...);
int		ft_isdigit(char c);
int		ft_is_flag(char c);
int		ft_is_conversion(char c);
int		ft_putchar(char c);
int		ft_putstrbylen(char *str, int len);
int		ft_parsing(char *format, va_list ap);
int		ft_flag_dot(char *format, int i, t_args *flags, va_list ap);
int		ft_parse_flags(char *format, int i, t_args *flags, va_list ap);
int		ft_convert_char(int c, t_args flags);
int		ft_check_conversion(char c, t_args flags, va_list ap);
int		ft_define_width(int width, int len, int zero);
int		ft_convert_string(char *str, t_args flags);
int		ft_convert_int(int nb, t_args flags);
int		ft_convert_percent(t_args flags);
int		ft_convert_unsigned_int(unsigned int n, t_args flags);
int		ft_convert_hexadecimal(unsigned int n, t_args flags, int maj);
int		ft_convert_pointer(unsigned long n, t_args flags);
t_args	ft_init_flags(void);
t_args	ft_flag_plus(t_args flags);
t_args	ft_flag_minus(t_args flags);
t_args	ft_flag_width(va_list ap, t_args flags);
t_args	ft_flag_isdigit(char c, t_args flags);
char	*ft_strdup(const char *s1);
char	*ft_itoa(long n);
char	*ft_utoa(unsigned int n);
char	*ft_convert_base(unsigned int n, char *base);
char	*ft_convert_base_ul(unsigned long n, char *base);
size_t	ft_strlen(const char *s1);

#endif
