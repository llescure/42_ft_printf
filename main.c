/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:32 by llescure          #+#    #+#             */
/*   Updated: 2021/01/20 23:13:26 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	/*char *test;

	t_flag all_flag;
	ft_initialisation(&all_flag);
	ft_parsing("%cabc", &all_flag);
	printf("flag%c\n", all_flag.type);
	ft_get_buf_start("%cabc", 3, &test);
	ft_print_cara("%cabc", all_flag, 'a', &test);
	printf("%s\n", test);*/
	//printf("%d\n", printf("%c", 'a'));
	ft_printf("myprintf%%abc\n");
	//printf("printf%%abc\n");
	//ft_printf("myprintf%-10cabc\n", 't');
	//printf("printf%-10cabc\n", 't');
	//printf("%d\n", ft_printf("%c", 'a'));
}
