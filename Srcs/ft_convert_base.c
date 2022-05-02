/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:45:19 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 13:54:10 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_size_nb(unsigned int n, unsigned int base)
{
	if (n < base)
		return (1);
	return (1 + ft_size_nb(n / base, base));
}

char	*ft_convert_base(unsigned int n, char *base)
{
	char	*str;
	int		size;
	int		base_size;

	base_size = ft_strlen(base);
	size = ft_size_nb(n, base_size);
	if (base_size < 2 || size == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = base[n % base_size];
		n /= base_size;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
