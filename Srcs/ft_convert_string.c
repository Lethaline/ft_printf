/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:00:23 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/01 17:04:06 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_convert_string(char *str, t_args flags)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += ft_putstrbylen("(null)", 6);
		return (count);
	}
	if ((flags.dot >= 0 && flags.dot > (int)ft_strlen(str)) || flags.dot < 0)
		flags.dot = (int)ft_strlen(str);
	if (flags.minus == 1)
		count += ft_putstrbylen(str, flags.dot);
	if (flags.dot >= 0)
		count += ft_define_width(flags.width, flags.dot, 0);
	else
		count += ft_define_width(flags.width, (int)ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_putstrbylen(str, flags.dot);
	return (count);
}
