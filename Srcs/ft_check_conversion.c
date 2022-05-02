/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:00:38 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/01 15:45:32 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_check_conversion(char c, t_args flags, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_convert_char(va_arg(ap, int), flags);
	else if (c == 's')
		count = ft_convert_string(va_arg(ap, char *), flags);
	else if (c == 'd' || c == 'i')
		count = ft_convert_int(va_arg(ap, int), flags);
	else if (c == 'u')
		count = ft_convert_unsigned_int(va_arg(ap, unsigned int), flags);
	else if (c == 'x')
		count = ft_convert_hexadecimal(va_arg(ap, unsigned int), flags, 0);
	else if (c == 'X')
		count = ft_convert_hexadecimal(va_arg(ap, unsigned int), flags, 1);
	else if (c == 'p')
		count = ft_convert_pointer(va_arg(ap, unsigned long), flags);
	else if (c == '%')
		count = ft_convert_percent(flags);
	return (count);
}
