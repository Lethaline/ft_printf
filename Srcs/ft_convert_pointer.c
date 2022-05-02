/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:46:32 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 13:57:05 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_minus_zero(char *str, t_args flags)
{
	int	count;

	count = 0;
	if ((flags.dot >= 0 || flags.dot == -2) && flags.dot < (int)ft_strlen(str))
			flags.dot = (int)ft_strlen(str);
	if (flags.zero == 1 || flags.dot >= flags.width)
	{
		count += ft_putstrbylen("0x", 2);
		if (flags.dot >= 0)
			count += ft_define_width(flags.dot, ft_strlen(str), 1);
		else
			count += ft_define_width(flags.width, ft_strlen(str) + 2, 1);
	}
	else
	{
		count += ft_define_width(flags.width, ft_strlen(str) + 2, 0);
		count += ft_putstrbylen("0x", 2);
	}
	count += ft_putstrbylen(str, ft_strlen(str));
	return (count);
}

static int	ft_puthexa_ulong(char *str, t_args flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putstrbylen("0x", 2);
		if (flags.dot > (int)ft_strlen(str))
			count += ft_define_width(flags.dot, ft_strlen(str), 1);
		count += ft_putstrbylen(str, ft_strlen(str));
		if ((flags.dot >= 0 || flags.dot == -2)
			&& flags.dot < (int)ft_strlen(str))
			flags.dot = (int)ft_strlen(str);
		if (flags.dot >= 0)
			count += ft_define_width(flags.width, flags.dot + 2, 0);
		else
			count += ft_define_width(flags.width, ft_strlen(str) + 2, 0);
	}
	if (flags.minus == 0)
		count = ft_minus_zero(str, flags);
	return (count);
}

static int	ft_print_diff_null(t_args flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putstrbylen("0x0", 3);
		count += ft_define_width(flags.width, 3, 0);
	}
	if (flags.minus == 0)
	{
		if (flags.zero == 0)
			count += ft_define_width(flags.width, 3, flags.zero);
		count += ft_putstrbylen("0x0", 3);
		if (flags.zero == 1)
			count += ft_define_width(flags.width, 3, flags.zero);
	}
	return (count);
}

int	ft_convert_pointer(unsigned long n, t_args flags)
{
	int		count;
	char	*str;

	count = 0;
	if (n == 0 && (flags.dot == 0 || flags.dot == -2))
	{
		if (flags.minus == 1)
			count += ft_putstrbylen("0x", 2);
		count += ft_define_width(flags.width, 2, 0);
		if (flags.minus == 0)
			count += ft_putstrbylen("0x", 2);
		return (count);
	}
	if (n == 0 && flags.dot == -1)
		return (ft_print_diff_null(flags));
	str = ft_convert_base_ul(n, "0123456789abcdef");
	count += ft_puthexa_ulong(str, flags);
	free(str);
	return (count);
}
