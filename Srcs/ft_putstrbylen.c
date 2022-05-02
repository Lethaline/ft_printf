/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrbylen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:35:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/27 16:03:01 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_putstrbylen(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		i += ft_putchar(str[i]);
	}
	return (i);
}
