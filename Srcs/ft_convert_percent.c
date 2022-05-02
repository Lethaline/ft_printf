/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:30:08 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 13:56:32 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_convert_percent(t_args flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putchar('%');
		count += ft_define_width(flags.width, 1, flags.zero);
	}
	if (flags.minus == 0)
	{
		count += ft_define_width(flags.width, 1, flags.zero);
		count += ft_putchar('%');
	}
	return (count);
}
