/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:06:36 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 13:55:35 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_treat_hexa_uint_part(char *str, t_args flags, int maj)
{
	int	count;

	count = 0;
	if (flags.hashtag == 1 && maj == 1)
		count += ft_putstrbylen("0X", 2);
	if (flags.hashtag == 1 && maj == 0)
		count += ft_putstrbylen("0x", 2);
	if (flags.dot >= 0)
		count += ft_define_width(flags.dot, ft_strlen(str), 1);
	count += ft_putstrbylen(str, ft_strlen(str));
	return (count);
}

static int	ft_puthexa_uint(char *str, t_args flags, int maj)
{
	int	count;

	count = 0;
	if (flags.hashtag == 1)
		flags.width -= 2;
	if (flags.minus == 1)
		count += ft_treat_hexa_uint_part(str, flags, maj);
	if ((flags.dot >= 0 || (flags.dot == -2 && flags.star == 0))
		&& flags.dot < (int)ft_strlen(str))
		flags.dot = (int)ft_strlen(str);
	if (flags.dot >= 0)
		count += ft_define_width(flags.width, flags.dot, 0);
	else
		count += ft_define_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_treat_hexa_uint_part(str, flags, maj);
	return (count);
}

int	ft_convert_hexadecimal(unsigned int n, t_args flags, int maj)
{
	int		count;
	char	*str;

	count = 0;
	if ((flags.dot == 0 || flags.dot == -2) && n == 0)
	{
		count += ft_define_width(flags.width, 0, 0);
		return (count);
	}
	if (n == 0)
		flags.hashtag = 0;
	if (maj == 1)
		str = ft_convert_base(n, "0123456789ABCDEF");
	else
		str = ft_convert_base(n, "0123456789abcdef");
	count += ft_puthexa_uint(str, flags, maj);
	free(str);
	return (count);
}
