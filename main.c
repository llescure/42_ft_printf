/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:32 by llescure          #+#    #+#             */
/*   Updated: 2021/01/18 14:49:06 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	t_flag all_flag;
	int compt;

	all_flag = ft_initialisation(&all_flag);
	compt = ft_parsing("coucou%*d", &all_flag);
	printf("compteur%d\n", compt);
	printf("%d\n", all_flag.wildcard);
	printf("%d\n", all_flag.minus);
	printf("%d\n", all_flag.dot);
	printf("%d\n", all_flag.zero);
	printf("%d\n", all_flag.number);
	printf("%c\n", all_flag.type);
	return (0);
}
