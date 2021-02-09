/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:48:24 by llescure          #+#    #+#             */
/*   Updated: 2021/02/09 22:49:49 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	process_wildcard(t_flag *all_flag, va_list arguments)
{
	int number_wildcard;

	number_wildcard = all_flag->wildcard;
	while (number_wildcard > 0 && number_wildcard < 3)
	{
		conv_wildcard(va_arg(arguments, int), number_wildcard, all_flag);
		number_wildcard--;
	}
}

void	conv_wildcard(int arguments, int number_wildcard,
		t_flag *all_flag)
{
	int rslt;

	rslt = arguments;
	if (number_wildcard == 2 || all_flag->wildcard == 1)
		all_flag->wildcard_value1 = rslt;
	if (number_wildcard == 1 && all_flag->wildcard == 2)
		all_flag->wildcard_value2 = rslt;
	return ;
}
