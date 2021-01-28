/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:32 by llescure          #+#    #+#             */
/*   Updated: 2021/01/28 16:51:02 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	//DEBUG
	//char *test = NULL;
	/*t_flag all_flag;
	int compt;

	ft_get_buf_start("%*dabc\n",  &test);
	ft_initialisation(&all_flag);
	ft_parsing("%*dabc\n", &all_flag, 0);
	all_flag.wildcard_value1 = 5;
	//printf("error%d\n", int_error_case(all_flag));
	//printf("type%c\n", all_flag.type);
	//printf("wildcard%d\n", all_flag.wildcard);
	//printf("number%d\n", all_flag.number);
	//compt = ft_print_low_hexa("%.0x\n", all_flag, 42 ,&test);
	//compt = ft_zero_int("%.0x\n", all_flag ,&test, "2a");
	//compt = ft_print_int("%*dabc\n", all_flag, 1, &test);
	compt = ft_space_int("%*dabc\n", all_flag, &test, "1");
	printf("%s\n", test);
	printf("%d\n", compt);*/

	//TEST p
	/*int *address;
	*address = 2;
	printf("%d\n", printf("%p\n", address));
	printf("%d\n", ft_printf("%p\n", address));
	printf("%d\n", printf("%p\n", test));
	printf("%d\n", ft_printf("%p\n", test));*/

	//TEST u
	/*printf("%d\n", printf("%u\n", 42));
	printf("%d\n", ft_printf("%u\n", 42));
	printf("%d\n", printf("%3u\n", 42));
	printf("%d\n", ft_printf("%3u\n", 42));
	printf("%d\n", printf("%3.4uabc\n", 42));
	printf("%d\n", ft_printf("%3.4uabc\n", 42));
	printf("%d\n", printf("%10.4u\n", 42));
	printf("%d\n", ft_printf("%10.4u\n", 42));
	printf("%d\n", printf("%3.5u\n", 42));
	printf("%d\n", ft_printf("%3.5u\n", 42));
	printf("%d\n", printf("%-3.5uabc\n", 42));
	printf("%d\n", ft_printf("%-3.5uabc\n", 42));
	printf("%d\n", printf("%0*.3uabc\n", 5, 42));
	printf("%d\n", ft_printf("%0*.3uabc\n", 5, 42));
	printf("%d\n", printf("%0*.*u\n", 3, 3, 42));
	printf("%d\n", ft_printf("%0*.*u\n", 3, 3, 42));
	printf("%d\n", printf("%0.u\n", 42));
	printf("%d\n", ft_printf("%0.u\n", 42));
	printf("%d\n", printf("%.0u\n", 42));
	printf("%d\n", ft_printf("%.0u\n", 42));
	printf("%d\n", printf("%0*u\n", 6, 42));
	printf("%d\n", ft_printf("%0*u\n", 6, 42));
	printf("%d\n", printf("%-0*u\n", 6, 42));
	printf("%d\n", ft_printf("%-0*u\n", 6, 42));
	printf("%d\n", printf("%-03u\n", 42));
	printf("%d\n", ft_printf("%-03u\n", 42));
	printf("%d\n", printf("%-5u\n", 123456789));
	printf("%d\n", ft_printf("%-5u\n", 123456789));
	printf("%d\n", printf("%-5u\n", -1));
	printf("%d\n", ft_printf("%-5u\n", -1));*/

	//TEST x AND X
	/*printf("%d\n", printf("%x\n", 42));
	printf("%d\n", ft_printf("%x\n", 42));
	printf("%d\n", printf("%3x\n", 42));
	printf("%d\n", ft_printf("%3x\n", 42));
	printf("%d\n", printf("%3.4xabc\n", 42));
	printf("%d\n", ft_printf("%3.4xabc\n", 42));
	printf("%d\n", printf("%10.4x\n", 42));
	printf("%d\n", ft_printf("%10.4x\n", 42));
	printf("%d\n", printf("%3.5x\n", 42));
	printf("%d\n", ft_printf("%3.5x\n", 42));
	printf("%d\n", printf("%-3.5xabc\n", 42));
	printf("%d\n", ft_printf("%-3.5xabc\n", 42));
	printf("%d\n", printf("%0*.3xabc\n", 5, 42));
	printf("%d\n", ft_printf("%0*.3xabc\n", 5, 42));
	printf("%d\n", printf("%0*.*x\n", 3, 3, 42));
	printf("%d\n", ft_printf("%0*.*x\n", 3, 3, 42));
	printf("%d\n", printf("%0.x\n", 42));
	printf("%d\n", ft_printf("%0.x\n", 42));
	printf("%d\n", printf("%.0x\n", 42));
	printf("%d\n", ft_printf("%.0x\n", 42));
	printf("%d\n", printf("%0*x\n", 6, 42));
	printf("%d\n", ft_printf("%0*x\n", 6, 42));
	printf("%d\n", printf("%-0*x\n", 6, 42));
	printf("%d\n", ft_printf("%-0*x\n", 6, 42));
	printf("%d\n", printf("%-03x\n", 42));
	printf("%d\n", ft_printf("%-03x\n", 42));
	printf("%d\n", printf("%-5X\n", 123456789));
	printf("%d\n", ft_printf("%-5X\n", 123456789));*/

	// MULTIPLE TYPES
	printf("%d\n", printf("%dabc%X%u%xabc\n", 1, 2, 3, 4));
	printf("%d\n", ft_printf("%dabc%X%u%xabc\n", 1, 2, 3, 4));
	printf("%d\n", printf("%d%%abc\n", 1));
	printf("%d\n", ft_printf("%d%%abc\n", 1));
	printf("%d\n", printf("%d%%abc%c\n", 1, 'l'));
	printf("%d\n", ft_printf("%d%%abc%c\n", 1, 'l'));
	printf("%d\n", printf("%dabc\n", 1));
	printf("%d\n", ft_printf("%dabc\n", 1));
	printf("%d\n", printf("abc\n"));
	printf("%d\n", ft_printf("abc\n"));
	printf("%d\n", printf("%*dabc\n", 5, 1));
	printf("%d\n", ft_printf("%*dabc\n", 5, 1));
	printf("%d\n", printf("%*dabc%*c\n", 5, 1, 10, 'a'));
	printf("%d\n", ft_printf("%*dabc%*c\n", 5, 1, 10, 'a'));

	//TEST STRING
	//printf("%d\n", printf("%*.abc10s\n", 10, "coucou"));
	//printf("%d\n", ft_printf("%*.abc10s\n", 10, "coucou"));
	/*printf("%d\n", printf("%.3s\n", "coucou"));
	printf("%d\n", ft_printf("%.3s\n", "coucou"));
	printf("%d\n", printf("%10.*s\n", 2, "coucou"));
	printf("%d\n", ft_printf("%10.*s\n", 2, "coucou"));
	printf("%d\n", printf("%-*.*s", 6, 2, "coucou"));
	printf("%d\n", ft_printf("%-*.*s", 6, 2, "coucou"));
	printf("%d\n", printf("%*.*s", 7, 2, "coucou"));
	printf("%d\n", ft_printf("%*.*s", 7, 2, "coucou"));
	printf("%d\n", printf("%.0s\n", "coucou"));
	printf("%d\n", ft_printf("%.0s\n", "coucou"));
	printf("%d\n", printf("abc%.3s\n", "coucou"));
	printf("%d\n", ft_printf("abc%.3s\n", "coucou"));
	printf("%d\n", printf("%-10s\n", test));
	printf("%d\n", ft_printf("%-10s\n", test));
	printf("%d", printf("%s\n", "coucou"));
	printf("%d", ft_printf("%s\n", "coucou"));*/
	//TEST CHAR
	//Test %
}
