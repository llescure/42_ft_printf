/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_up_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 22:28:13 by llescure          #+#    #+#             */
/*   Updated: 2021/02/11 12:27:03 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_up_hexa(const char **str, t_flag *all_flag, int user_nbr)
{
	char							*nbr_convert;
	int								i;

	i = 0;
	int_error_case(all_flag, str);
	if (all_flag->compt == -1)
		return ;
	nbr_convert = ft_convert_hexa((unsigned int)user_nbr, "0123456789ABCDEF");
	if ((all_flag->number > 0 || all_flag->wildcard > 0 || all_flag->dot > 0) &&
			(all_flag->minus == 0) && (all_flag->zero == 0))
		ft_space_int(*str, all_flag, nbr_convert, i);
	else if (all_flag->minus > 0 && all_flag->zero == 0)
		ft_space_minus_int(*str, all_flag, nbr_convert, i);
	else if (all_flag->zero > 0 && (all_flag->number > 0 ||
				all_flag->wildcard > 0))
		ft_zero_int(*str, all_flag, nbr_convert, i);
	else
	{
		ft_putstr_fd(nbr_convert, 1);
		all_flag->compt = all_flag->compt + ft_strlen(nbr_convert);
	}
	free(nbr_convert);
	return ;
}
