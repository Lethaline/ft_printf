/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:28:57 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/30 11:49:10 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_size_uint(unsigned int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}
static unsigned int ft_convert(unsigned int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int ft_sign(unsigned int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	long	nb;
	int		size;
	int		minus; 

	nb = ft_convert(n);
	size = ft_size_uint(n);
	minus = ft_sign(n);
	if (n != 0)
		str = (char *)malloc(sizeof(char) * size + 1);
	else
		return (ft_strdup("0"));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	if (minus == 1)
		str[0] = '-';
	return (str);
}