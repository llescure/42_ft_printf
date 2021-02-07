/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:38:22 by llescure          #+#    #+#             */
/*   Updated: 2021/02/07 12:50:25 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_zero_percent(const char *str, t_flag *all_flag, char cara)
{
	int						i;
	int						number_of_zero;

	i = 0;
	number_of_zero = 0;
	while (str[i] == '0' || ft_isdigit(str[i]) != 1)
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	if (all_flag->number > 0)
		number_of_zero = ft_extract_number(str, i) - 1;
	else if (all_flag->wildcard > 0)
		number_of_zero = all_flag->wildcard_value1 - 1;
	number_of_zero = ft_create_cara(number_of_zero, '0');
	ft_putchar_fd(cara, 1);
	all_flag->compt = all_flag->compt + 1 + number_of_zero;
	return ;
}

void	ft_print_percent(const char **str, t_flag *all_flag)
{
	int_error_case(all_flag, str);
	if (all_flag->compt == -1)
		return ;
	if ((all_flag->number > 0 || all_flag->wildcard > 0) &&
			all_flag->minus == 0 && all_flag->zero == 0)
		ft_space(*str, all_flag, '%');
	else if (all_flag->minus > 0 && (all_flag->number > 0 ||
		all_flag->wildcard > 0) && all_flag->zero == 0)
		ft_space_minus(*str, all_flag, '%');
	else if (all_flag->zero > 0 && (all_flag->number > 0 ||
				all_flag->wildcard > 0))
		ft_zero_percent(*str, all_flag, '%');
	else
	{
		ft_putchar_fd('%', 1);
		all_flag->compt = all_flag->compt + 1;
	}
	return ;
}
