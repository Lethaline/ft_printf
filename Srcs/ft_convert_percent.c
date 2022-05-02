/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:30:08 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/27 16:36:29 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_convert_percent(t_args flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putchar('%');
		count += ft_define_width(flags.width, 1, 0);
	}
	else
	{
		count += ft_define_width(flags.width, 1, 0);
		count += ft_putchar('%');
	}
	return (count);
}