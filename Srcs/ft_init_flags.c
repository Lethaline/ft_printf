/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:37:53 by lolemmen          #+#    #+#             */
/*   Updated: 2022/04/27 16:02:15 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

t_args	ft_init_flags(void)
{
	t_args	flags;

	flags.minus = 0;
	flags.plus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.hashtag = 0;
	flags.space = 0;
	flags.width = 0;
	flags.star = 0;
	return (flags);
}
