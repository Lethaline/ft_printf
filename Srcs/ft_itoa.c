/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:33:46 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 13:58:12 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_size_int(long n)
{
	int	size;

	size = 0;
	if (n <= 0)
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

static int	ft_sign(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static long	ft_convert(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(long n)
{
	char			*str;
	int				minus;
	int				size;
	long			nbr;

	size = ft_size_int(n);
	minus = ft_sign(n);
	nbr = ft_convert(n);
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size] = nbr % 10 + 48;
		nbr /= 10;
		size--;
	}
	if (minus == 1)
		str[0] = '-';
	return (str);
}
