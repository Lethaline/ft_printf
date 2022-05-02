/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:08:20 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/26 15:52:25 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	*str;

	str = ft_strdup(format);
	len = 0;
	va_start(ap, format);
	len += ft_parsing(str, ap);
	va_end(ap);
	free((char *)str);
	return (len);
}
