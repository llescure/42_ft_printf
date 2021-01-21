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
	char *test;

	t_flag all_flag;
	ft_initialisation(&all_flag);
	ft_parsing("abc%c", &all_flag);
	ft_get_buf_start("abc%c", 3, &test);
	ft_print_cara("abc%c", all_flag, 'a', &test);
	printf("%s\n", test);
	//printf("%d\n", printf("abc%c", 'a'));
	printf("%d\n", ft_printf("abc%c", 'a'));
}
