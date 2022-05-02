/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:19:08 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/27 15:17:41 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

t_args	ft_flag_plus(t_args flags)
{
	flags.space = 0;
	flags.plus = 1;
	return (flags);
}

t_args	ft_flag_minus(t_args flags)
{
	flags.zero = 0;
	flags.minus = 1;
	return (flags);
}

t_args	ft_flag_width(va_list ap, t_args flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width *= -1;
	}
	return (flags);
}

t_args	ft_flag_isdigit(char c, t_args flags)
{
	if (flags.star == 1)
	{
		flags.width = 0;
		flags.star = 0;
	}
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}

int	ft_flag_dot(char *format, int i, t_args *flags, va_list ap)
{
	int	j;

	j = i;
	j++;
	flags->star = 0;
	if (format[j] == '*')
	{
		flags->star = 1;
		flags->dot = va_arg(ap, int);
		j++;
	}
	else if (ft_isdigit(format[j]))
	{
		flags->dot = 0;
		while (ft_isdigit(format[j]))
		{
			flags->dot = (flags->dot * 10) + (format[j] - 48);
			j++;
		}
	}
	else
		flags->dot = -2;
	return (j);
}
