/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:32:35 by llescure          #+#    #+#             */
/*   Updated: 2021/01/26 21:32:06 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_int(const char *str, t_flag all_flag, int user_nbr,
	char **buf)
{
	char *temp1;
	char *nbr_convert;

	nbr_convert = ft_itoa(user_nbr);
	if (int_error_case(all_flag) < 0)
		return (-1);
	if ((all_flag.number > 0 || all_flag.wildcard > 0 || all_flag.dot > 0) &&
			(all_flag.minus == 0) && (all_flag.zero == 0))
		return (ft_space_int(str, all_flag, buf, nbr_convert));
	else if (all_flag.minus > 0 && (all_flag.number > 0 ||
				all_flag.wildcard > 0) && all_flag.zero == 0)
		return (ft_space_minus_int(str, all_flag, buf, nbr_convert));
	else if (all_flag.zero > 0 && (all_flag.number > 0 ||
				all_flag.wildcard > 0))
		return (ft_zero_int(str, all_flag, buf, nbr_convert));
	else
	{
		temp1 = *buf;
		*buf = ft_strjoin(*buf, nbr_convert);
		free(temp1);
	}
	return ((int)ft_strlen(*buf));
}
