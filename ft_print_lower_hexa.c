/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:49:00 by llescure          #+#    #+#             */
/*   Updated: 2021/01/24 22:47:05 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		int_error_case(t_flag all_flag)
{
	if (all_flag.minus > 0 && all_flag.wildcard == 0 &&
		all_flag.number == 0)
		return (-1);
	if (all_flag.zero > 0 && all_flag.wildcard == 0 &&
		all_flag.number == 0)
		return (-1);
	if ((all_flag.wildcard > 2) || (all_flag.minus > 1) || (all_flag.dot > 1) ||
		(all_flag.zero > 1))
		return (-1);
	return (0);
}

int		ft_space_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr)
{
	int						i;
	int						number_of_spaces;
	int						number_of_char;
	char					*temp1;

	i = 0;
	number_of_char = ft_strlen(user_nbr);
	number_of_spaces = 0;
	if (all_flag.dot > 0)
	{
		number_of_char = ft_precision(str, all_flag);
		ft_join_buf_zero(buf, number_of_char - ft_strlen(user_nbr));
	}
	while (ft_isdigit(str[i] != 1))
		i++;
	if (number_of_char > (int)ft_strlen(user_nbr))
			number_of_char= ft_strlen(user_nbr);
	if (all_flag.number > 0)
		number_of_spaces = ft_extract_number(str, i) - number_of_char -
			ft_strlen(user_nbr);
	else if (all_flag.wildcard > 0)
		number_of_spaces = all_flag.wildcard_value1 - number_of_char -
			ft_strlen(user_nbr);
	ft_join_buf_space(buf, number_of_spaces);
	return (ft_strlen(*buf));
}

int		ft_space_minus_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr)
{
	int								i;
	int								number_of_spaces;
	int								number_of_char;
	char							*temp1;
	char							*temp2;

	i = 0;
	number_of_spaces = 0;
	number_of_char = ft_strlen(user_nbr);
	if (all_flag.dot > 0)
		number_of_char = ft_precision(str, all_flag);
	temp1 = *buf;
	temp2 = ft_trim(user_nbr, 0, number_of_char);
	*buf = ft_strjoin(*buf, temp2);
	free(temp1);
	free(temp2);
	while (str[i] != '-')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = ft_extract_number(str, i) - number_of_char;
	else if (str[i] == '-' && str[i + 1] == '*')
		number_of_spaces = all_flag.wildcard_value1 - number_of_char;
	if ((ft_join_buf_space(buf, number_of_spaces)) == -1)
		return (-1);
	return (ft_strlen(*buf));
}

int		ft_print_low_hexa(const char *str, t_flag all_flag, int user_nbr,
	char **buf)
{
	char *temp1;
	char *nbr_convert;

	nbr_convert = ft_convert_lower_hexa(int user_nbr);
	if (str_error_case(all_flag) < 0)
		return (-1);
	if ((all_flag.number > 0 || all_flag.wildcard > 0 || all_flag.dot > 0) &&
			(all_flag.minus == 0))
		return (ft_space_string(str, all_flag, buf, nbr_convert));
	else if (all_flag.minus > 0  && (all_flag.number > 0 ||
				   	all_flag.wildcard > 0))
		return (ft_space_minus_string(str, all_flag, buf, nbr_convert));
	else if (all_flag.zero > 0  && (all_flag.number > 0 ||
				   	all_flag.wildcard > 0))
		return (ft_zero_string(str, all_flag, buf, nbr_convert));
	else
	{
		temp1 = *buf;
		*buf = ft_strjoin(*buf, nbr_convert);
		free(temp1);
	}
	return ((int)ft_strlen(*buf));
}
