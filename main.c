/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:32 by llescure          #+#    #+#             */
/*   Updated: 2021/01/25 23:22:13 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	/*char *test = NULL;
	t_flag all_flag;
	int compt;

	ft_get_buf_start("%.0x\n", 0,  &test);
	ft_initialisation(&all_flag);
	ft_parsing("%.0x\n", &all_flag);
	//all_flag.wildcard_value1 = 6;
	//printf("error%d\n", int_error_case(all_flag));
	//printf("zero%d\n", all_flag.zero);
	//printf("wildcard%d\n", all_flag.wildcard);
	//printf("number%d\n", all_flag.number);
	//compt = ft_print_low_hexa("%0*x\n", all_flag, 42 ,&test);
	//compt = ft_zero_int("%0*x\n", all_flag ,&test, "2a");
	compt = ft_space_int("%.0x\n", all_flag ,&test, "2a");*/
	//printf("%s\n", test);
	//printf("%d\n", compt);

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
	printf("%d\n", ft_printf("%0*.*x\n", 3, 3, 42));*/
	//printf("%d\n", printf("%0.x\n", 42));
	//printf("%d\n", ft_printf("%0.x\n", 42));
	printf("%d\n", printf("%.0x\n", 42));
	printf("%d\n", ft_printf("%.0x\n", 42));
	printf("%d\n", printf("%0*x\n", 6, 42));
	printf("%d\n", ft_printf("%0*x\n", 6, 42));
	printf("%d\n", printf("%-0*x\n", 6, 42));
	printf("%d\n", ft_printf("%-0*x\n", 6, 42));
	printf("%d\n", printf("%-03x\n", 42));
	printf("%d\n", ft_printf("%-03x\n", 42));

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
