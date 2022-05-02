/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:30:51 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 11:28:33 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_printf.h"
#include "limits.h"
#include "stdlib.h"

int	main(void)
{
	printf("%d\n", ft_printf("%i\n", -42));
	printf("%d\n", printf("%i\n", -42));
}
