
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 00:16:33 by llescure          #+#    #+#             */
/*   Updated: 2021/02/09 10:52:15 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "libftprintf.h"

int		main(void)
{
	//DEBUG
//	char *test = NULL;
//	const char *str = "%0*.%\n";
//	t_flag all_flag;
//	ft_get_buf_start("%*.*s\n",  &all_flag);
//	ft_initialisation(&all_flag);
//	ft_parsing(str, &all_flag);
//	all_flag.wildcard_value1 = 2;
//	all_flag.wildcard_value2 = -4;
//	int_error_case(&all_flag, &str);
	//printf("error%d\n", int_error_case(all_flag));
	//printf("type%c\n", all_flag.type);
	//printf("wildcard%d\n", all_flag.wildcard);
	//printf("number%d\n", all_flag.number);
	//compt = ft_print_low_hexa("%.0x\n", all_flag, 42 ,&test);
	//compt = ft_zero_int("%.0x\n", all_flag ,&test, "2a");
	//compt = ft_print_int("%*dabc\n", all_flag, 1, &test);
//	ft_zero_percent(str, &all_flag, '%');

	//TEST p
	/*int *address;
	*address = 2;
	printf("%d\n", printf("%p\n", address));
	printf("%d\n", ft_printf("%p\n", address));
	printf("%d\n", printf("%p\n", test));
	printf("%d\n", ft_printf("%p\n", test));*/

	//TEST u
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

	//TEST x AND X
/*	printf("%d\n", printf("%x\n", 42));
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
	/*printf("%d\n", printf("%dabc%X%u%xabc\n", 1, 2, 3, 4));
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
	printf("%d\n", ft_printf("%*dabc%*c\n", 5, 1, 10, 'a'));*/

	//TEST STRING
	/*printf("%d\n", printf("%*.abc10s\n", 10, "coucou"));
	printf("%d\n", ft_printf("%*.abc10s\n", 10, "coucou"));
	printf("%d\n", printf("%.3s\n", "coucou"));
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
/*	printf("%d\n", printf("%c\n" , '\0'));
	printf("%d\n", ft_printf("%c\n" , '\0'));
	printf("%d\n", printf("%5c\n" , 'a'));
	printf("%d\n", ft_printf("%5c\n" , 'a'));
	printf("%d\n", printf("%-5c\n" , 'a'));
	printf("%d\n", ft_printf("%-5c\n" , 'a'));
	printf("%d\n", printf("coucou%-5c copain\n" , 'a'));
	printf("%d\n", ft_printf("coucou%-5c copain\n" , 'a'));
	printf("%d\n", printf("coucou%-------5c lolo\n" , 'a'));
	printf("%d\n", ft_printf("coucou%-------5c lolo\n" , 'a'));
	printf("%d\n", printf("%c%c%c\n" , 'a', 'b', 'c'));
	printf("%d\n", ft_printf("%c%c%c\n" , 'a', 'b', 'c'));
	printf("%d\n", printf("%c%c%c\n" , 'a', 'b', 'c'));
	printf("%d\n", ft_printf("%c%c%c\n" , 'a', 'b', 'c'));
	printf("%d\n", printf("coucou %cmon %c ami %c\n" , 'a', 'b', 'c'));
	printf("%d\n", ft_printf("coucou %cmon %c ami %c\n" , 'a', 'b', 'c'));
	printf("%d\n", printf("coucou %c mon %c ami %c\n" , 'a', 'b', 'c'));
	printf("%d\n", ft_printf("coucou %c mon %c ami %c\n" , 'a', 'b', 'c'));*/

	//Test %
/*	printf("%d\n", printf("%%\n"));
	printf("%d\n", printf("%%\n"));
	printf("%d\n", printf("%5%\n"));
	printf("%d\n", printf("%5%\n"));
	printf("%d\n", printf("%-5%\n"));
	printf("%d\n", printf("%-5%\n"));
	printf("%d\n", printf("abc%5%\n"));
	printf("%d\n", printf("abc%5%\n"));
	printf("%d\n", printf("%05%\n"));
	printf("%d\n", printf("%05%\n"));
	printf("%d\n", printf("%05%%c\n", 'a'));
	printf("%d\n", printf("%05%%c\n", 'a')); */

	//TEST mega testeur
	//printf("%d\n", printf("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20));
	//printf("%d\n", ft_printf("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20));
//	printf("%d\n", printf("***************%*s%*d**************%*u*************\n", 10, "coucou", 10, 10, -50, 20));
//	printf("%d\n", ft_printf("***************%*s%*d**************%*u*************\n", 10, "coucou", 10, 10, -50, 20));
//	printf("%d\n", printf("-->|%-4.3%|<--\n"));
//	printf("%d\n", printf("-->|%-4.3%|<--\n"));
//	printf("%d\n", printf("-->|%*%|<--\n", 0));
//	printf("%d\n", printf("-->|%*%|<--\n", 0));
//	printf("%d\n", printf("-->|%*.c|<--\n", 2, 'c'));
//	printf("%d\n", ft_printf("-->|%*.c|<--\n", 2, 'c'));
//	printf("%d\n", printf("-->|%2.c|<--\n", 'c'));
//	printf("%d\n", ft_printf("-->|%2.c|<--\n", 'c'));
//	printf("%d\n", printf("-->|%*c|<--\n", 0, 'c'));
//	printf("%d\n", ft_printf("-->|%*c|<--\n", 0, 'c'));
	//printf("%d\n", printf("-->|%*.c|<--\n", 10, 'c'));
	//printf("%d\n", ft_printf("-->|%*.c|<--\n", 10, 'c'));
//	printf("%d\n", printf("-->|%-16.p|<--\n", test));
//	printf("%d\n", ft_printf("-->|%-16.p|<--\n", test));
//	printf("%d\n", printf("-->|%-4.4d|<--\n", 135));
//	printf("%d\n", ft_printf("-->|%-4.4d|<--\n", 135));
//	printf("%d\n", printf("-->|%00.*d|<--\n", -4, 135));
//	printf("%d\n", ft_printf("-->|%00.*d|<--\n", -4, 135));
//	printf("%d\n", printf("-->|%00.*d|<--\n", -3, 135));
//	printf("%d\n", ft_printf("-->|%00.*d|<--\n", -3, 135));
//	printf("%d\n", printf("-->|%*.*d|<--\n", -4, -4, 135));
//	printf("%d\n", ft_printf("-->|%*.*d|<--\n", -4, -4, 135));
//	printf("%d\n", printf("-->|%0*.*d|<--\n", 4, -8, 135));
//	printf("%d\n", ft_printf("-->|%0*.*d|<--\n", 4, -2, 135));
//	printf("%d\n", printf("-->|%*.*%|<--\n", 2, -4));
//	printf("%d\n", ft_printf("-->|%*.*%|<--\n", 2, -4));
//	printf("%d\n", printf("-->|%0.0%|<--\n"));
//	printf("%d\n", ft_printf("-->|%0.0%|<--\n"));
//	printf("%d\n", printf("-->|%0.*%|<--\n", 2));
//	printf("%d\n", ft_printf("-->|%0.*%|<--\n", 2));
//	printf("%d\n", printf("-->|%00.3%|<--\n"));
//	printf("%d\n", ft_printf("-->|%00.3%|<--\n"));
//	printf("%d\n", printf("-->|%0*.%|<--\n", 2));
//	printf("%d\n", ft_printf("-->|%0*.%|<--\n", 2));
	printf("%d\n", printf("%-90.*%%-*.169s%-129.46d%-26.100X%-57.36u\n" ,178,-108,"N(Z",-1790829278,1376263938u,1964629019u));
	printf("%d\n", ft_printf("%-90.*%%-*.169s%-129.46d%-26.100X%-57.36u\n" ,178,-108,"N(Z",-1790829278,1376263938u,1964629019u));

}
