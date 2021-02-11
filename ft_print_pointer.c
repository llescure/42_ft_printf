/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:36:12 by llescure          #+#    #+#             */
/*   Updated: 2021/02/11 12:25:58 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_space_pointer(const char *str, t_flag *all_flag, char *user_nbr)
{
	int						i;
	int						number_of_spaces;

	i = 0;
	number_of_spaces = 0;
	while (ft_isdigit(str[i]) != 1 && str[i] != '\0')
		i++;
	if (all_flag->number > 0 && ft_isdigit(str[i]) == 1)
		number_of_spaces = ft_extract_number(str, i) - ft_strlen(user_nbr);
	else if (all_flag->wildcard > 0)
		number_of_spaces = all_flag->wildcard_value1 - ft_strlen(user_nbr);
	number_of_spaces = ft_create_cara(number_of_spaces, ' ');
	ft_putstr_fd(user_nbr, 1);
	all_flag->compt = all_flag->compt + ft_strlen(user_nbr) + number_of_spaces;
	return ;
}

void	ft_space_minus_pointer(const char *str, t_flag *all_flag,
		char *user_nbr)
{
	int								i;
	int								number_of_spaces;

	i = 0;
	number_of_spaces = 0;
	ft_putstr_fd(user_nbr, 1);
	while (str[i] != '%')
		i++;
	while (str[i] != '-')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = ft_extract_number(str, i) - ft_strlen(user_nbr);
	if ((str[i] == '-' && str[i + 1] == '*'))
		number_of_spaces = all_flag->wildcard_value1 - ft_strlen(user_nbr);
	number_of_spaces = ft_create_cara(number_of_spaces, ' ');
	all_flag->compt = all_flag->compt + ft_strlen(user_nbr) + number_of_spaces;
	return ;
}

void	print_point(const char **str, t_flag *all_flag,
		long unsigned user_nbr)
{
	char *nbr_convert;

	error_case(all_flag, str);
	if (all_flag->compt == -1)
		return ;
	nbr_convert = ft_convert_address(user_nbr, *all_flag);
	if ((all_flag->number > 0 || all_flag->wildcard > 0) &&
			(all_flag->minus == 0))
		ft_space_pointer(*str, all_flag, nbr_convert);
	else if (all_flag->minus > 0 && (all_flag->number > 0 ||
				all_flag->wildcard > 0))
		ft_space_minus_pointer(*str, all_flag, nbr_convert);
	else
	{
		ft_putstr_fd(nbr_convert, 1);
		all_flag->compt = all_flag->compt + ft_strlen(nbr_convert);
	}
	if (!(all_flag->dot > 0 && user_nbr == 0))
		free(nbr_convert);
	return ;
}
