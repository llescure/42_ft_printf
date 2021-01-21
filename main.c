/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:32 by llescure          #+#    #+#             */
/*   Updated: 2021/01/21 23:00:13 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	int a = 6;
	int *test = &a;
	
	/*t_flag all_flag;
	ft_initialisation(&all_flag);
	ft_parsing("%10cabc\n", &all_flag);
	printf("error%d\n", error_case(all_flag));
	ft_get_buf_start("%10cabc\n", 0, &test);
	ft_space("%10cabc\n", all_flag, &test, 't');
	printf("%s\n", test);
	ft_print_cara("%10cabc\n", all_flag, 't', &test);
	printf("%s\n", test);*/
	//printf("%d\n", printf("%c", 'a'));
	//ft_printf("abc%-10cabc\n", 't');
	printf("%p\n", test);
	printf("%x\n", test);
	//ft_printf("coucou\n");
	//printf("coucou\n");
	//printf("%d\n", ft_printf("%c", 'a'));
}
