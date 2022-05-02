/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:09:05 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/27 09:51:11 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == '#' || c == '*' || c == '.'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'x'
		|| c == 'X' || c == 'p' || c == 'u' || c == '%')
		return (1);
	return (0);
}

void	check_format(t_args *flags)
{
	printf("- : %d\n", flags->minus);
	printf("+ : %d\n", flags->plus);
	printf("0 : %d\n", flags->zero);
	printf(". : %d\n", flags->dot);
	printf("# : %d\n", flags->hashtag);
	printf("  : %d\n", flags->space);
	printf("w : %d\n", flags->width);
	printf("* : %d\n", flags->star);
}
