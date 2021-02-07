/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:49:56 by llescure          #+#    #+#             */
/*   Updated: 2021/02/07 00:34:36 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_change_user_nbr(char **user_nbr, t_flag *all_flag)
{
	char *copy;

	all_flag->negative = 1;
	copy = *user_nbr;
	*user_nbr = ft_strdup(&copy[1]);
	free(copy);
}

void		ft_print_int(const char **str, t_flag *all_flag, int user_nbr)
{
	char *nbr_convert;

	nbr_convert = ft_itoa(user_nbr);
	int_error_case(all_flag, str);
	if (all_flag->compt == -1)
		return ;
	if ((all_flag->number > 0 || all_flag->wildcard > 0 || all_flag->dot > 0) &&
			(all_flag->minus == 0) && (all_flag->zero == 0))
		ft_space_int(*str, all_flag, nbr_convert);
	else if (all_flag->minus > 0 && (all_flag->number > 0 ||
				all_flag->wildcard > 0) && all_flag->zero == 0)
		ft_space_minus_int(*str, all_flag, nbr_convert);
	else if (all_flag->zero > 0)
		ft_zero_int(*str, all_flag, nbr_convert);
	else
	{
		ft_putstr_fd(nbr_convert, 1);
		all_flag->compt = all_flag->compt + ft_strlen(nbr_convert);
	}
	return ;
}
