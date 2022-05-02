/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:24:27 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 13:56:12 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_treat_int_part(char *str, t_args flags, int nb)
{
	int	count;

	count = 0;
	if (nb < 0 && (flags.dot >= 0 || flags.zero == 0 || flags.minus == 1
			|| flags.plus == 1 || flags.space == 1))
		ft_putchar('-');
	if (nb > 0 && flags.dot >= 0 && flags.plus == 1)
		ft_putchar('+');
	if (flags.dot >= 0)
		count += ft_define_width(flags.dot, ft_strlen(str), 1);
	count += ft_putstrbylen(str, ft_strlen(str));
	return (count);
}

static int	ft_putint(char *str, t_args flags, int nb)
{
	int	count;

	count = 0;
	if (nb >= 0 && (flags.plus == 1 || flags.space == 1))
	{
		if (flags.plus == 1)
			count += ft_putchar('+');
		else
			count += ft_putchar(' ');
		flags.width--;
	}
	if (flags.minus == 1)
		count += ft_treat_int_part(str, flags, nb);
	if ((flags.dot >= 0 || (flags.dot == -2 && flags.star == 0))
		&& flags.dot < (int)ft_strlen(str))
		flags.dot = (int)ft_strlen(str);
	if (flags.dot >= 0)
		count += ft_define_width(flags.width, flags.dot, 0);
	else if (flags.minus == 1 || flags.space == 1 || flags.zero == 0)
		count += ft_define_width(flags.width, ft_strlen(str), 0);
	else
		count += ft_define_width(flags.width, ft_strlen(str), 1);
	if (flags.minus == 0)
		count += ft_treat_int_part(str, flags, nb);
	return (count);
}

int	ft_convert_int(int nb, t_args flags)
{
	int		count;
	long	memory;
	char	*str;

	count = 0;
	memory = (long)nb;
	if ((flags.dot == 0 || (flags.dot == -2 && flags.star == 0))
		&& memory == 0)
		return (ft_define_width(flags.width, 0, 0));
	if (memory < 0)
	{
		if (((flags.dot <= -1 && flags.star == 1)
				|| (flags.dot == -1 && flags.star == 0)) && flags.zero == 1
			&& flags.space == 0)
			ft_putchar('-');
		memory *= -1;
		flags.width--;
		count++;
	}
	str = ft_itoa(memory);
	count += ft_putint(str, flags, nb);
	free(str);
	return (count);
}
