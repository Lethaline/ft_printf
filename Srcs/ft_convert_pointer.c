/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:46:32 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/01 16:04:52 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_puthexa_ulong(char *str, t_args flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putstrbylen("0x", 2);
		count += ft_putstrbylen(str, ft_strlen(str));
	}
	count += ft_define_width(flags.width, ft_strlen(str) + 2, 0);
	if (flags.minus == 0)
	{
		count += ft_putstrbylen("0x", 2);
		count += ft_putstrbylen(str, ft_strlen(str));
	}
	return (count);
}

int	ft_convert_pointer(unsigned long n, t_args flags)
{
	int	count;
	char	*str;

	count = 0;
	str = ft_convert_base_ul(n, "0123456789abcdef");
	count += ft_puthexa_ulong(str, flags);
	free(str);
	return (count);
}