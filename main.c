/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:32 by llescure          #+#    #+#             */
/*   Updated: 2021/01/18 12:37:54 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	t_flag all_flag;

	all_flag.wildcard = 0;
	all_flag.minus = -1;
	all_flag.dot = -1;
	all_flag.zero = -1;
	all_flag.number = -1;
	all_flag.type = '0';	
	all_flag = ft_initialisation(all_flag);
	printf("%d", all_flag.wildcard);
	printf("%d", all_flag.minus);
	printf("%d", all_flag.dot);
	printf("%d", all_flag.zero);
	printf("%d", all_flag.number);
	printf("%c", all_flag.type);
	return (0);
}
