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
	char c = 'b';
	char *str = "Bonjour";
	void *voider = "Bonjour";
	void *nullpointer = NULL;
	char *nullstr = NULL;
	unsigned int nbr = 123;

	printf("%d\n", ft_printf("1 : %%\n"));
	printf("%d\n", printf("1 : %%\n"));
	printf("%d\n", ft_printf("2 : %15%\n"));
	printf("%d\n", printf("2 : %15%\n"));
	printf("%d\n", ft_printf("3 : %-10.5x\n", -42));
	printf("%d\n", printf("3 : %-10.5x\n", -42));
	printf("%d\n", ft_printf("4 : %-10.5X\n", 42));
	printf("%d\n", printf("4 : %-10.5X\n", 42));
	printf("%d\n", ft_printf("5 : %-10.5u\n", -42));
	printf("%d\n", printf("5 : %-10.5u\n", -42));
	printf("%d\n", ft_printf("6 : %-10.5i\n", -42));
	printf("%d\n", printf("6 : %-10.5i\n", -42));
	printf("%d\n", ft_printf("7 : % 10.5d\n", -42));
	printf("%d\n", printf("7 : % 10.5d\n", -42));
	printf("%d\n", ft_printf("8 : %-+10.5d\n", -42));
	printf("%d\n", printf("8 : %-+10.5d\n", -42));
	printf("%d\n", ft_printf("9 : %15p\n", NULL));
	printf("%d\n", printf("9 : %15p\n", NULL));
	printf("%d\n", ft_printf("10 : %-15.5s\n", str));
	printf("%d\n", printf("10 : %-15.5s\n", str));
	printf("%d\n", ft_printf("11 : %-15c\n", c));
	printf("%d\n", printf("11 : %-15c\n", c));
	printf("%d\n", ft_printf("NULL char : %c\n", '\0'));
	printf("%d\n", printf("NULL char : %c\n", '\0'));
	printf("%d\n", ft_printf("NULL str : %s\n", nullstr));
	printf("%d\n", printf("NULL str : %s\n", nullstr));
	printf("%d\n", ft_printf("NULL nb : %d\n", 0));
	printf("%d\n", printf("NULL nb : %d\n", 0));
	printf("%d\n", ft_printf("NULL pointer : {%4.p}\n", nullpointer));
	printf("%d\n", printf("NULL pointer : {%4.p}\n", nullpointer));
	printf("%d\n", ft_printf("NULL hexa : %x\n", 0));
	printf("%d\n", printf("NULL hexa : %x\n", 0));
	printf("%d\n", ft_printf("NULL HEXA : %X\n", 0));
	printf("%d\n", printf("NULL HEXA : %X\n", 0));
	printf("%d\n", ft_printf("NULL uint : %u\n", 0));
	printf("%d\n", printf("NULL uint : %u\n", 0));
	printf("%d\n", ft_printf("MIX : %c, %s, %d, %i, %x, %X, %p, %u\n", c, str, -42, 42, 1234, -1234, voider, -1234));
	printf("%d\n", printf("MIX : %c, %s, %d, %i, %x, %X, %p, %u\n", c, str, -42, 42, 1234, -1234, voider, -1234));
	printf("%d\n", ft_printf("MIX with flags : %-12c, %5s, % d, %+i, %#x, %#12X, %20p, %.5u\n", c, str, -42, 42, 1234, -1234, voider, -1234));
	printf("%d\n", printf("MIX with flags : %-12c, %5s, % d, %+i, %#x, %#12X, %20p, %.5u\n", c, str, -42, 42, 1234, -1234, voider, -1234));
	printf("%d\n", ft_printf("null dot : {%.d}\n", 0));
	printf("%d\n", printf("null dot : {%.d}\n", 0));
	printf("%d\n", ft_printf("null dot : {%.x}\n", 0));
	printf("%d\n", printf("null dot : {%.x}\n", 0));
	printf("%d\n", ft_printf("null dot : {%.s}\n", "42"));
	printf("%d\n", printf("null dot : {%.s}\n", "42"));
	printf("%d\n", ft_printf("null dot : {%4.s}\n", "42"));
	printf("%d\n", printf("null dot : {%4.s}\n", "42"));
	printf("%d\n", ft_printf("null dot : {%.p}\n", (void *)0));
	printf("%d\n", printf("null dot : {%.p}\n", (void *)0));
	printf("%d\n", ft_printf("null dot : {%.d}\n", 0));
	printf("%d\n", printf("null dot : {%.d}\n", 0));
	printf("%d\n", ft_printf("null dot : {%.0d}\n", 0));
	printf("%d\n", printf("null dot : {%.0d}\n", 0));
	printf("%d\n", ft_printf("null dot : {%.0x}\n", 0));
	printf("%d\n", printf("null dot : {%.0x}\n", 0));
	printf("%d\n", ft_printf("null dot : {%.0u}\n", 0));
	printf("%d\n", printf("null dot : {%.0u}\n", 0));
	printf("%d\n", ft_printf("null dot : {%.u}\n", 0));
	printf("%d\n", printf("null dot : {%.u}\n", 0));
	printf("%d\n", ft_printf("{%146.146s}\n" ,NULL));
	printf("%d\n", printf("{%146.146s}\n" ,NULL));
	printf("%d\n", ft_printf("%--101.115u\n%00114.174%\n" ,1158010145u));
	printf("%d\n", printf("%--101.115u\n%00114.174%\n" ,1158010145u));
	printf("%d\n", ft_printf("%-91.78X\n%-85.50X\n%-195.180i\n" ,597874775u,2208405511u,1625226049));
	printf("%d\n", printf("%-91.78X\n%-85.50X\n%-195.180i\n" ,597874775u,2208405511u,1625226049));
	printf("%d\n", ft_printf("%--87.18d%180p%-130.84u" ,213284615,(void*)12365356750099397136lu,3648680271u));
	printf("%d\n", printf("%--87.18d%180p%-130.84u" ,213284615,(void*)12365356750099397136lu,3648680271u));
	printf("%d\n", ft_printf("{%3.1s}\n", NULL));
	printf("%d\n", printf("{%3.1s}\n", NULL));
	printf("%d\n", ft_printf("%.s\n", "hello"));
	printf("%d\n", printf("%.s\n", "hello"));
	printf("%d\n", ft_printf("{%4.3s}\n{%-7.4s}\n", "hello", "world"));
	printf("%d\n", printf("{%4.3s}\n{%-7.4s}\n", "hello", "world"));
	printf("%d\n", ft_printf("%0093.u\n", nbr));
	printf("%d\n", printf("%0093.u\n", nbr));
	printf("%d\n", ft_printf("{%-*.48u}\n" ,-95,2428147040u));
	printf("%d\n", printf("{%-*.48u}\n" ,-95,2428147040u));
	printf("%d\n", ft_printf("{%0025.d}\n" ,1910242786));
	printf("%d\n", printf("{%0025.d}\n" ,1910242786));
	printf("%d\n", ft_printf("{%--191.%}\n{%026.159u}\n{%0*.137%}\n" ,1410971553u,-199));
	printf("%d\n", printf("{%--191.%}\n{%026.159u}\n{%0*.137%}\n" ,1410971553u,-199));
	printf("%d\n", ft_printf("{%155c}\n{%00*.x}\n{%-88%}\n" ,39,79,1886386166u));
	printf("%d\n", printf("{%155c}\n{%00*.x}\n{%-88%}\n" ,39,79,1886386166u));
	printf("%d\n", ft_printf("{%0185.*X}\n" ,-2,3540052352u));
	printf("%d\n", printf("{%0185.*X}\n" ,-2,3540052352u));
	printf("%d\n", ft_printf("{%00125.*i}\n" ,-69,-544350427));
	printf("%d\n", printf("{%00125.*i}\n" ,-69,-544350427));
	printf("%d\n", ft_printf("{%00169.d}\n" ,-513924419));
	printf("%d\n", printf("{%00169.d}\n" ,-513924419));
	printf("%d\n", ft_printf("{%015p}\n", 1234));
	printf("%d\n", printf("{%015p}\n", 1234));
	printf("%d\n", ft_printf("{%021s}\n", NULL));
	printf("%d\n", printf("{%021s}\n", NULL));
	printf("%d\n", ft_printf("{%--187p}\n" ,(void*)5092148362367175078lu));
	printf("%d\n", printf("{%--187p}\n" ,(void*)5092148362367175078lu));
	printf("%d\n", ft_printf("{%015p}\n", NULL));
	printf("%d\n", printf("{%015p}\n", NULL));
	printf("%d\n", ft_printf("{%-15p}\n", NULL));
	printf("%d\n", printf("{%-15p}\n", NULL));
}
