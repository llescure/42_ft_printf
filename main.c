/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:32 by llescure          #+#    #+#             */
/*   Updated: 2021/01/27 23:34:31 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	/*char *test = NULL;
	//void *address = "coucou";
	t_flag all_flag;
	//int compt;

	//ft_get_buf_start("%.0x\n", 0,  &test);
	ft_initialisation(&all_flag);
	ft_parsing("%d%i%u\n", &all_flag, 0);
	//all_flag.wildcard_value1 = 6;
	//printf("error%d\n", int_error_case(all_flag));
	printf("%c\n", all_flag.type);*/
	//printf("wildcard%d\n", all_flag.wildcard);
	//printf("number%d\n", all_flag.number);
	//compt = ft_print_low_hexa("%.0x\n", all_flag, 42 ,&test);
	//compt = ft_zero_int("%.0x\n", all_flag ,&test, "2a");
	//compt = ft_space_int("%.0x\n", all_flag ,&test, "2a");
	//printf("%s\n", test);
	//printf("%d\n", compt);

	//Test p
	//printf("%d\n", printf("%p\n", test));
	//printf("%d\n", printf("%p\n", address));
	//printf("%d\n", ft_printf("%p\n", address));
	//printf("%d\n", printf("%p\n", test));
	//printf("%d\n", ft_printf("%p\n", test));


	//Test u and U
/*	printf("%d\n", printf("%u\n", 42));
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

	//Test x and X
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

	//printf("%d\n", printf("%d%i%d%dabc\n", 1, 2, 3, 4));
	//printf("%d\n", ft_printf("%d%i%d%dabc\n", 1, 2, 3, 4));
	printf("%d\n", printf("%dabc\n", 1));
	printf("%d\n", ft_printf("%dabc\n", 1));
	printf("%d\n", printf("abc\n"));
	printf("%d\n", ft_printf("abc\n"));

	//Test string
	//printf("%d\n", printf("%*.abc10s\n", 10, "coucou"));
	//printf("%d\n", ft_printf("%*.abc10s\n", 10, "coucou"));
	/*printf("%d\n", printf("%*.10s\n", 10, "coucou"));
	printf("%d\n", ft_printf("%*.10s\n", 10, "coucou"));
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

	//Test char
	//Test %
}
