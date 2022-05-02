/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:06:44 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/30 09:44:33 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_parsing(char *format, va_list ap)
{
	t_args	flags;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!format[i])
			break ;
		else if (format[i] == '%' && format[i + 1])
		{
			i = ft_parse_flags(format, i, &flags, ap);
			if (ft_is_conversion(format[i]))
			{
				len += ft_check_conversion(format[i], flags, ap);
			}
			else if (format[i])
				len += ft_putchar(format[i]);
		}
		else if (format[i] != '%')
			len += ft_putchar(format[i]);
		i++;
	}
	return (len);
}
