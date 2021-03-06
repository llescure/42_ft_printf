/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:50:16 by llescure          #+#    #+#             */
/*   Updated: 2021/02/11 12:24:05 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	int_error_case(t_flag *all_flag, const char **str)
{
	if ((all_flag->wildcard > 2) || (all_flag->dot > 1))
		all_flag->compt = -1;
	if (all_flag->wildcard_value1 < 0 &&
			check_weird_combination(str, all_flag) == 0)
		*str = replace_first_wildcard(*str, '-', all_flag);
	if (all_flag->wildcard_value2 < 0 &&
			check_weird_combination(str, all_flag) == 0)
		*str = replace_second_wildcard(*str, '-', all_flag);
	if (all_flag->zero > 0)
		*str = ft_delete_multiple_cara(str, '0');
	if (all_flag->zero > 0 && (all_flag->minus > 0 || (all_flag->dot > 0 &&
					all_flag->type != '%')))
	{
		if (ft_delete_cara(*str, '0', *all_flag) == NULL)
			return ;
		*str = ft_delete_cara(*str, '0', *all_flag);
		all_flag->zero = 0;
	}
	if (all_flag->minus > 1)
		*str = ft_delete_multiple_cara(str, '-');
	return ;
}

void	ft_space_int(const char *str, t_flag *all_flag, char *user_nbr, int i)
{
	int						spaces;
	int						number_of_char;

	spaces = 0;
	number_of_char = ft_strlen(user_nbr);
	if (all_flag->dot > 0)
	{
		if (ft_atoi(user_nbr) < 0 && all_flag->type != 'u')
			spaces = ft_change_user_nbr(&user_nbr, all_flag);
		number_of_char = ft_precision(str, *all_flag, &user_nbr);
	}
	while ((str[i] == '0' || ft_isdigit(str[i]) != 1) && str[i] != '\0' &&
			str[i] != '*')
		i++;
	if (ft_isdigit(str[i]) == 1)
		spaces = spaces + ft_extract_number(str, i) - number_of_char;
	else if (str[i] == '*')
		spaces = spaces + all_flag->wildcard_value1 - number_of_char;
	spaces = ft_create_cara(spaces, ' ');
	if (all_flag->negative == 1)
		ft_putchar_fd('-', 1);
	ft_create_cara(number_of_char - ft_strlen(user_nbr), '0');
	ft_putstr_fd(user_nbr, 1);
	all_flag->compt = all_flag->compt + spaces + number_of_char;
}

void	ft_zero_int(const char *str, t_flag *all_flag, char *user_nbr, int i)
{
	int						number_of_zero;

	number_of_zero = 0;
	if (ft_atoi(user_nbr) < 0 && all_flag->type != 'u')
		number_of_zero = ft_change_user_nbr(&user_nbr, all_flag);
	while ((str[i] == '0' || ft_isdigit(str[i]) != 1) && str[i] != '\0' &&
			str[i] != '*')
		i++;
	if (ft_isdigit(str[i]) == 1)
		number_of_zero = number_of_zero + ft_extract_number(str, i) -
			ft_strlen(user_nbr);
	else if (str[i] == '*')
		number_of_zero = number_of_zero + all_flag->wildcard_value1 -
			ft_strlen(user_nbr);
	if (all_flag->negative == 1)
		ft_putchar_fd('-', 1);
	number_of_zero = ft_create_cara(number_of_zero, '0');
	ft_putstr_fd(user_nbr, 1);
	all_flag->compt = all_flag->compt + number_of_zero + ft_strlen(user_nbr);
}

void	ft_space_minus_int(const char *str, t_flag *all_flag,
		char *user_nbr, int i)
{
	int								spaces;
	int								number_of_char;

	spaces = 0;
	number_of_char = ft_strlen(user_nbr);
	if (all_flag->dot > 0)
	{
		if (ft_atoi(user_nbr) < 0 && all_flag->type != 'u')
		{
			spaces = ft_change_user_nbr(&user_nbr, all_flag);
			ft_putchar_fd('-', 1);
		}
		number_of_char = ft_precision(str, *all_flag, &user_nbr);
		ft_create_cara(number_of_char - ft_strlen(user_nbr), '0');
	}
	ft_putstr_fd(user_nbr, 1);
	while (str[i] != '-')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		spaces = spaces + ft_extract_number(str, i) - number_of_char;
	if ((str[i] == '-' && str[i + 1] == '*'))
		spaces = spaces + all_flag->wildcard_value1 - number_of_char;
	spaces = ft_create_cara(spaces, ' ');
	all_flag->compt = all_flag->compt + spaces + number_of_char;
}

void	ft_print_low_hexa(const char **str, t_flag *all_flag, int user_nbr)
{
	char							*nbr_convert;
	int								i;

	i = 0;
	int_error_case(all_flag, str);
	if (all_flag->compt == -1)
		return ;
	nbr_convert = ft_convert_hexa((unsigned int)user_nbr, "0123456789abcdef");
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
