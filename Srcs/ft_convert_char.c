/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:21:31 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/27 10:59:43 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_convert_char(int c, t_args flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putchar(c);
		count += ft_define_width(flags.width, 1, flags.zero);
	}
	else
	{
		count += ft_define_width(flags.width, 1, flags.zero);
		count += ft_putchar(c);
	}
	return (count);
}
