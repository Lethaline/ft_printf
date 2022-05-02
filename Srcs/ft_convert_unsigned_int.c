/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:43:24 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 13:58:02 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_treat_uint_part(char *str, t_args flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_define_width(flags.dot, ft_strlen(str), 1);
	count += ft_putstrbylen(str, ft_strlen(str));
	return (count);
}

static int	ft_putuint(char *str, t_args flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_treat_uint_part(str, flags);
	if ((flags.dot >= 0 || flags.dot == -2) && flags.dot < (int)ft_strlen(str))
		flags.dot = (int)ft_strlen(str);
	if (flags.dot >= 0)
		count += ft_define_width(flags.width, flags.dot, 0);
	else
		count += ft_define_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_treat_uint_part(str, flags);
	return (count);
}

int	ft_convert_unsigned_int(unsigned int n, t_args flags)
{
	int		count;
	char	*str;

	count = 0;
	if ((flags.dot == 0 || flags.dot == -2) && n == 0)
	{
		count += ft_define_width(flags.width, 0, 0);
		return (count);
	}
	str = ft_utoa(n);
	count += ft_putuint(str, flags);
	free(str);
	return (count);
}
