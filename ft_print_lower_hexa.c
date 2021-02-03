/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:50:16 by llescure          #+#    #+#             */
/*   Updated: 2021/02/03 12:35:50 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		int_error_case(t_flag *all_flag, const char **str)
{
	if ((all_flag->wildcard > 2) || (all_flag->dot > 1))
		return (-1);
	if (all_flag->wildcard_value1 < 0)
	{
		*str = check_weird_combination(str, all_flag);
		all_flag->wildcard_value1 = all_flag->wildcard_value1 * -1;
		all_flag->minus = all_flag->minus + 1;
		*str = replace_first_wildcard(str, '-');
	}
	if (all_flag->wildcard_value2 < 0)
	{
		*str = check_weird_combination(str, all_flag);
		all_flag->wildcard_value2 = all_flag->wildcard_value2 * -1;
		all_flag->minus = all_flag->minus + 1;
		*str = replace_second_wildcard(str, '-');
	}
	if (all_flag->minus > 1)
		*str = ft_delete_multiple_cara(str, '-');
	if (all_flag->zero > 1)
		*str = ft_delete_multiple_cara(str, '0');
	if (all_flag->zero > 0 && (all_flag->dot > 0 || all_flag->minus > 0))
	{
		*str = ft_delete_cara(str, '0');
		all_flag->zero = 0;
	}
	return (0);
}

int		ft_space_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr)
{
	int						i;
	int						number_of_spaces;
	int						number_of_char;
	char					*temp1;

	i = -1;
	number_of_char = ft_strlen(user_nbr);
	number_of_spaces = 0;
	if (all_flag.dot > 0)
	{
		if (ft_atoi(user_nbr) < 0)
		{
			number_of_spaces = -1;
			ft_change_user_nbr(&user_nbr, &all_flag);
		}
		number_of_char = ft_precision(str, all_flag, &user_nbr);
	}
	while (str[++i] == '0' || ft_isdigit(str[i]) != 1)
	{
		if (str[i] == '\0' || str[i] == '*')
			break ;
	}
	if (all_flag.number > 0 && ft_isdigit(str[i]) == 1)
		number_of_spaces = number_of_spaces + ft_extract_number(str, i) - number_of_char;
	else if (all_flag.wildcard > 0)
		number_of_spaces = number_of_spaces + all_flag.wildcard_value1 - number_of_char;
	ft_join_buf_space(buf, number_of_spaces);
	if (all_flag.negative == 1)
		ft_print_minus(buf);
	ft_join_buf_zero(buf, number_of_char - ft_strlen(user_nbr));
	temp1 = *buf;
	*buf = ft_strjoin(*buf, user_nbr);
	free(temp1);
	return (ft_strlen(*buf));
}

int		ft_zero_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr)
{
	int						i;
	int						number_of_spaces;
	char					*temp1;

	i = 0;
	number_of_spaces = 0;
	if (ft_atoi(user_nbr) < 0)
	{
		number_of_spaces = -1;
		ft_change_user_nbr(&user_nbr, &all_flag);
	}
	while (str[i] == '0' || ft_isdigit(str[i]) != 1)
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	if (all_flag.number > 0)
		number_of_spaces = number_of_spaces + ft_extract_number(str, i) - ft_strlen(user_nbr);
	else if (all_flag.wildcard > 0)
		number_of_spaces = number_of_spaces + all_flag.wildcard_value1 - ft_strlen(user_nbr);
	if (all_flag.negative == 1)
		ft_print_minus(buf);
	ft_join_buf_zero(buf, number_of_spaces);
	temp1 = *buf;
	*buf = ft_strjoin(*buf, user_nbr);
	free(temp1);
	return (ft_strlen(*buf));
}

int		ft_space_minus_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr)
{
	int								i;
	int								number_of_spaces;
	int								number_of_char;
	char							*temp1;

	i = 0;
	number_of_spaces = 0;
	number_of_char = ft_strlen(user_nbr);
	if (all_flag.dot > 0)
	{
		if (ft_atoi(user_nbr) < 0)
		{
			number_of_spaces = -1;
			ft_change_user_nbr(&user_nbr, &all_flag);
			ft_print_minus(buf);
		}
		number_of_char = ft_precision(str, all_flag, &user_nbr);
		ft_join_buf_zero(buf, number_of_char - ft_strlen(user_nbr));
	}
	temp1 = *buf;
	*buf = ft_strjoin(*buf, user_nbr);
	free(temp1);
	while (str[i] != '-')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = number_of_spaces + ft_extract_number(str, i) - number_of_char;
	if ((str[i] == '-' && str[i + 1] == '*') ||
			(ft_extract_number(str, i) == 0))
		number_of_spaces = number_of_spaces + all_flag.wildcard_value1 - number_of_char;
	ft_join_buf_space(buf, number_of_spaces);
	return (ft_strlen(*buf));
}

int		ft_print_low_hexa(const char *str, t_flag all_flag, int user_nbr,
	char **buf)
{
	char *temp1;
	char *nbr_convert;

	nbr_convert = ft_convert_lower_hexa(user_nbr, "0123456789abcdef");
	if (int_error_case(&all_flag, &str) < 0)
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
