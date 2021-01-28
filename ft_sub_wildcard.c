/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:48:24 by llescure          #+#    #+#             */
/*   Updated: 2021/01/28 10:41:51 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_wildcard(int arguments, int number_wildcard,
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
