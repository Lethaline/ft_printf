/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:11:56 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/30 10:10:27 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_parse_flags(char *format, int i, t_args *flags, va_list ap)
{
	while (format[i++])
	{
		if (!ft_isdigit(format[i]) && !ft_is_flag(format[i])
			&& !ft_is_conversion(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == ' ' && flags->plus == 0)
			flags->space = 1;
		if (format[i] == '#')
			flags->hashtag = 1;
		if (format[i] == '+')
			*flags = ft_flag_plus(*flags);
		if (format[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (format[i] == '.')
			i = ft_flag_dot(format, i++, flags, ap);
		if (format[i] == '*')
			*flags = ft_flag_width(ap, *flags);
		if (ft_isdigit(format[i]))
			*flags = ft_flag_isdigit(format[i], *flags);
		if (ft_is_conversion(format[i]))
			break ;
	}
	return (i);
}
