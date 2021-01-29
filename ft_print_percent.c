/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:38:22 by llescure          #+#    #+#             */
/*   Updated: 2021/01/29 10:36:16 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_zero_percent(const char *str, t_flag all_flag, char **buf,
		char cara)
{
	int						i;
	int						number_of_spaces;
	char					*temp;
	char					*str_cara;

	i = 0;
	str_cara = NULL;
	number_of_spaces = 0;
	if (all_flag.minus > 0)
		return (ft_space_minus(str, all_flag, buf, cara));
	while (str[i] == '0' || ft_isdigit(str[i]) != 1)
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	if (all_flag.number > 0)
		number_of_spaces = ft_extract_number(str, i) - 1;
	else if (all_flag.wildcard > 0)
		number_of_spaces = all_flag.wildcard_value1 - 1;
	ft_join_buf_zero(buf, number_of_spaces);
	str_cara = ft_allocate_char_to_str(str_cara, cara);
	temp = *buf;
	*buf = ft_strjoin(*buf, str_cara);
	free(temp);
	free(str_cara);
	return (ft_strlen(*buf));
}

int		ft_print_percent(const char *str, t_flag all_flag, char **buf)
{
	char *str_cara;
	char *temp;

	str_cara = NULL;
	if (int_error_case(all_flag) < 0)
		return (-1);
	if ((all_flag.number > 0 || all_flag.wildcard > 0) &&
			all_flag.minus == 0 && all_flag.zero == 0)
		return (ft_space(str, all_flag, buf, '%'));
	else if (all_flag.minus > 0 && (all_flag.number > 0 ||
		all_flag.wildcard > 0) && all_flag.zero == 0)
		return (ft_space_minus(str, all_flag, buf, '%'));
	else if (all_flag.zero > 0 && (all_flag.number > 0 ||
				all_flag.wildcard > 0))
		return (ft_zero_percent(str, all_flag, buf, '%'));
	else
	{
		if ((str_cara = ft_allocate_char_to_str(str_cara, '%')) == NULL)
			return (-1);
		temp = *buf;
		*buf = ft_strjoin(*buf, str_cara);
		free(temp);
	}
	return ((int)ft_strlen(*buf));
}
